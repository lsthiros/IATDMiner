`timescale 1ns / 1ps
/* Bitcoin Block Solver: A pipelined Bitcoin POW calculator
 * This block is responsible for searching through all possible nonces to find
 * a solution for a given block header. Bitcoin POW algorithm is
 * SHA-256(SHA-256(header)). The result of the calculation is compared against
 * the provided target. In this implementation the algorithm is pipelined as:
 * SHA inner -> Sha Outer -> comparison
 */
module block_solver (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	input [255:0] midstate,
	input [95:0] header_leftovers,
	input [255:0] target,

	output [2:0] state_out,
	output [31:0] current_nonce
);

reg [2:0] state;

wire [255:0] reversed_hash;
wire [511:0] first_hash_start = {header_leftovers, nonce, 8'h80, 360'b0, 16'h0280};
wire [511:0] second_hash_start = {inner_hash, 8'h80, 232'b0, 16'h0100};

reg [31:0] nonce;

reg inner_valid;
reg [255:0] inner_hash;
reg [31:0] inner_nonce;

reg outer_valid;
reg [255:0] outer_hash;
reg [31:0] outer_nonce;


/* SHA starting state. i.e. 32 bits of the fractional part of the squares of
 * the first 8 primes
 */
wire [255:0] sha_initial_values = {
	32'h6a09e667,
    32'hbb67ae85,
    32'h3c6ef372,
    32'ha54ff53a,
    32'h510e527f,
    32'h9b05688c,
    32'h1f83d9ab,
    32'h5be0cd19
};

wire [255:0] finished_inner;
wire [255:0] finished_outer;

wire inner_sha_done;
wire outer_sha_done;

wire inner_sha_start;

wire sha_start;

sha_core inner_score(
	.clk(clk),
	.start_state  (midstate),
	.input_message(first_hash_start),
	.result       (finished_inner),
	.start        (inner_sha_start),
	.done         (inner_sha_done),
	.rst          (rst_n)
	);

sha_core outer_score(
	.clk          (clk),
	.start_state  (sha_initial_values),
	.input_message(second_hash_start),
	.result       (finished_outer),
	.start        (outer_sha_start),
	.done         (outer_sha_done),
	.rst          (rst_n)
	);

generate 
	genvar i;
	for (i = 0; i < 32; i=i+1)
	begin: something
		localparam integer j = 31 - i;
		assign reversed_hash[8 * (i + 1) - 1 : 8 * i] = outer_hash[8 * (j + 1) - 1 : 8 * j];
	end
endgenerate

assign state_out = state;
assign inner_sha_start = (state == TRANSITION && (!inner_valid || nonce != 0)) ? 1 : 0;
assign outer_sha_start = (state == TRANSITION && inner_valid) ? 1 : 0;
assign current_nonce = outer_nonce;

parameter WORKING = 0;
parameter TRANSITION = 1;
parameter SOLUTION_FOUND = 2;
parameter NO_SOLUTION = 3;

/* State Transition Description
 * TRANSITION:
 * Starts calculations on valid portions of the pipeline.
 * WORKING:
 * waiting for done signals. When done signals are asserted, nonce is increased
 * and passed to the next stage of the pipeline. Results are passed into the
 * next states of the pipeline. 
 */
always @ (posedge clk)
begin
	if (!rst_n) begin
		nonce <= 0;
		state <= TRANSITION;
		inner_valid <= 0;
		outer_valid <= 0;
	end
	else
	begin
		case (state)
			WORKING: begin
				if (inner_sha_done && (outer_sha_done || !inner_valid)) begin
					state <= TRANSITION;
					nonce <= nonce + 1;
					inner_nonce <= nonce;
					outer_nonce <= inner_nonce;
					inner_valid <= 1;
					outer_valid <= inner_valid;
					inner_hash  <= finished_inner;
					outer_hash  <= finished_outer;
				end
			end
			TRANSITION: begin
				if (reversed_hash < target && outer_valid) begin
					state <= SOLUTION_FOUND;
				end
				else if (outer_valid && outer_nonce == {32{1'b1}}) begin
					state <= NO_SOLUTION;
				end
				else begin
					state <= WORKING;
				end
			end
			default: begin
				state <= state;
			end
		endcase
	end
end

endmodule
