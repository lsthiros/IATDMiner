module block_solver (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	input [255:0] midstate,
	input [95:0] header_leftovers,
	input [255:0] target,

	output reg [1:0] state_out,
	output reg [31:0] nonce
);  

enum logic [2:0] {NO_SOLUTION, WORKING, WORKING_2_PRE, WORKING_2, SOLUTION_FOUND} state;

wire [255:0] finished_hash;
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

reg sha_start;

sha_core score(
	.clk(clk),
	.start_state  (sha_start_state),
	.input_message(sha_message),
	.result       (finished_hash),
	.start        (sha_start),
	.done         (sha_done),
	.rst          (rst_n)
	);

generate
	genvar i;
	genvar j;
	for (i = 0; i < 32; i++)
	begin
		j = 31 - i;
		assign reversed_hash[8 * (i + 1) - 1 : 8 * i] = finished_hash[8 * (j + 1) - 1 : 8 * j];
	end
endgenerate

initial
begin
	nonce <= 0;
	state <= NO_SOLUTION;
	sha_start <= 0;
end

assign sha_start_state = (state == WORKING) ? midstate : sha_initial_values;
assign sha_message = (state == WORKING) ? first_hash_start : second_hash_start;

always @ (posedge clk)
begin
	if (!rst_n) begin
		nonce <= 0;
		state <= WORKING;
		sha_start <= 1;
	end
	else
	begin
		case (state)
			/* This state is spent working through the portion of the inner
			 * hash of the block checking algorithm. It continues from the
			 * midstate
			 */
			WORKING: begin

				if (sha_start) sha_start <= 0;
				if (sha_done) begin
					sha_start <= 1;
					state <= WORKING_2_PRE;
				end
			end
			/* WORKING_2_PRE evades a bad design artifact of the sha_core where
			 * the FINISHED line is asserted until the cycle after a new start.
			 */
			
			/* WORKING_2 represents the outer SHA256 calculation. It is only
			 * after this operation that the solution conditions are checked
			 */
			WORKING_2: begin
				if (sha_start) sha_start <= 0;
				if (sha_done) begin
					if (reversed_hash < target) begin
			 			state <= SOLUTION_FOUND;
			 		end
			 		else if (nonce != {32{1'b1}}) begin
			 			nonce <= nonce + 1;
			 			state <= WORKING;
			 			sha_start <= 1;
			 		end
			 		else begin
			 			state <= NO_SOLUTION;
			 		end
			 	end
			end
			/* Nothing is done in any other state
			 */
			default: begin
			end
		endcase
	end
end

endmodule