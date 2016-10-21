`timescale 1ns / 1ps
module block_solver_test (
);

reg clk = 0;
reg rst_n = 0;
integer i = 0;

wire [255:0] midstate = 256'h4a03aeb2bcf3ad77d705828c4ec62fa2282784a285936a72c71636a4ddef7254;
wire [255:0] target = 256'h00000000000000000440C4000000000000000000000000000000000000000000;
wire [2:0] state_out;
wire [31:0] nonce;
wire [95:0] header_leftovers = 96'h15274c646c51f957c4400418;

block_solver uut (
	.clk             (clk),
	.rst_n           (rst_n),
	.midstate        (midstate),
	.target          (target),
	.state_out       (state_out),
	.header_leftovers(header_leftovers),
	.nonce           (nonce));


always #1 clk = !clk;

initial
begin : TEST_CASE
    $dumpfile("dumpout.vcd");
    $dumpvars(0, uut);
	#2;
	rst_n = 1;
	#2;
	force uut.nonce = 32'h9c9a4fc0;
	release uut.nonce;
	while (1)
	begin
		if (state_out == 3'h5 || state_out == 3'h4) begin
			$finish;
		end
		#1;
	end
	$finish;
end

endmodule