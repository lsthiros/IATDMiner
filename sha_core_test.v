`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/12/2016 11:03:28 PM
// Design Name: 
// Module Name: sha_core_test
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sha_core_test(
    );
    reg clk;
    reg start;
    wire [31:0] sha_start [0:7];
    wire [511:0] empty_message = {1'b1, 511'b0};
    wire [511:0] short_message = {24'h616263, 8'h80, 472'h0, 8'h18};
    wire [511:0] long_message = {440'h6162636462636465636465666465666765666768666768696768696a68696a6b696a6b6c6a6b6c6d6b6c6d6e6c6d6e6f6d6e6f706e6f70,
        8'h80, 48'h0, 16'h01b8};
    reg [511:0] test_message;
    wire done;
    
    assign sha_start[0] = 32'h6a09e667;
    assign sha_start[1] = 32'hbb67ae85;
    assign sha_start[2] = 32'h3c6ef372;
    assign sha_start[3] = 32'ha54ff53a;
    assign sha_start[4] = 32'h510e527f;
    assign sha_start[5] = 32'h9b05688c;
    assign sha_start[6] = 32'h1f83d9ab;
    assign sha_start[7] = 32'h5be0cd19;
    
    wire [255:0] sha_start_1d;
    wire [255:0] result;
    
    generate
    genvar i;
    for (i = 7; i >= 0; i=i-1) assign sha_start_1d[32 * i + 31: i * 32] = sha_start[7 - i];
    endgenerate
    
    initial
    begin
        // $dumpfile("dumpout.lxt");
        // $dumpvars(0, uut);
        #1
        test_message = empty_message;
        clk = 0;
        start = 0;
        #2 start = 1;
        #5 start = 0;
        #700
        test_message = short_message;
        start = 1;
        #10 start = 0;
        #700
        test_message = long_message;
        start = 1;
        #10 start = 0;
        #700
        $finish;
    end
    
    always #5 clk = !clk;
    sha_core uut (
        .start_state(sha_start_1d),
        .input_message(test_message),
        .clk(clk),
        .done(done),
        .start(start),
        .result(result),
        .rst          (1)
    );
endmodule
