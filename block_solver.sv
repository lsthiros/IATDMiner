`timescale 1ns / 1ps
module block_solver (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	input [255:0] midstate,
	input [95:0] header_leftovers,
	input [255:0] target,

	output [2:0] state_out,
	output reg [31:0] nonce
);  
parameter WORKING_PRE =  3'h0;
parameter WORKING = 3'h1;
parameter WORKING_SECOND_PRE = 3'h2;
parameter WORKING_SECOND = 3'h3;
parameter SOLUTION_FOUND = 3'h4;
parameter NO_SOLUTION = 3'h5;

reg [2:0] state;

reg [255:0] finished_hash;
wire [255:0] finished_hash_out;
wire [255:0] reversed_hash;
wire [511:0] first_hash_start = {header_leftovers, nonce, 8'h80, 360'b0, 16'h0280};
wire [511:0] second_hash_start = {finished_hash, 8'h80, 232'b0, 16'h0100};

wire [255:0] sha_start_state;
wire [511:0] sha_message;


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

wire sha_done;

wire sha_start;

sha_core score(
	.clk(clk),
	.start_state  (sha_start_state),
	.input_message(sha_message),
	.result       (finished_hash_out),
	.start        (sha_start),
	.done         (sha_done),
	.rst          (rst_n)
	);

generate 
	genvar i;
	for (i = 0; i < 32; i=i+1)
	begin: something
		localparam integer j = 31 - i;
		assign reversed_hash[8 * (i + 1) - 1 : 8 * i] = finished_hash[8 * (j + 1) - 1 : 8 * j];
	end
endgenerate

initial
begin
	nonce <= 0;
	state <= NO_SOLUTION;
	finished_hash <= 0;
end

assign sha_start_state = (state == WORKING) ? midstate : sha_initial_values;
assign sha_message = (state == WORKING) ? first_hash_start : second_hash_start;
assign state_out = state;
assign sha_start = (state == WORKING_PRE || state == WORKING_SECOND_PRE) ? 1 : 0;

always @ (posedge clk)
begin
	if (!rst_n) begin
		nonce <= 0;
		state <= WORKING_PRE;
	end
	else
	begin
		case (state)
			WORKING_PRE: begin
				state <= WORKING;
			end
			/* This state is spent working through the portion of the inner
			 * hash of the block checking algorithm. It continues from the
			 * midstate
			 */
			WORKING: begin
				if (sha_done) begin
					state <= WORKING_SECOND_PRE;
					finished_hash <= finished_hash_out;
				end
				nonce <= nonce;
			end


			/* WORKING_SECOND represents the outer SHA256 calculation. It is only
			 * after this operation that the solution conditions are checked
			 */
			WORKING_SECOND: begin
				if (sha_done) begin
					if (reversed_hash < target) begin
			 			state <= SOLUTION_FOUND;
			 		end
			 		else if (nonce != {32{1'b1}}) begin
			 			nonce <= nonce + 1;
			 			state <= WORKING_PRE;
			 		end
			 		else begin
			 			state <= NO_SOLUTION;
			 		end
			 	end
			end
 			/* WORKING_SECOND_PRE evades a bad design artifact of the sha_core where
			 * the FINISHED line is asserted until the cycle after a new start.
			 */
			WORKING_SECOND_PRE: begin
				state <= WORKING_SECOND;
				nonce <= nonce;
			end
			/* Nothing is done in any other state
			 */
			default: begin
				state <= NO_SOLUTION;
			end
		endcase
	end
end

endmodule