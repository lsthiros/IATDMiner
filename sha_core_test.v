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
    wire [31:0] midstate_start [0:7];
    wire [511:0] empty_message = {1'b1, 511'b0};
    wire [511:0] short_message = {24'h616263, 8'h80, 472'h0, 8'h18};
    wire [511:0] long_message = {440'h6162636462636465636465666465666765666768666768696768696a68696a6b696a6b6c6a6b6c6d6b6c6d6e6c6d6e6f6d6e6f706e6f70,
        8'h80, 48'h0, 16'h01b8};
    wire [511:0] header_message = 512'h15274c646c51f957c44004189c9a4fcb800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000280;
    wire [511:0] hash_message = 512'h53556ee487598a8944d3bb710913c3211bdd9496f664d723bf0be1926228889f8000000000000000000000000000000000000000000000000000000000000100;
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

    assign midstate_start[0] = 32'h4A03AEB2;
    assign midstate_start[1] = 32'hBCF3AD77;
    assign midstate_start[2] = 32'hD705828C;
    assign midstate_start[3] = 32'h4EC62FA2;
    assign midstate_start[4] = 32'h282784A2;
    assign midstate_start[5] = 32'h85936A72;
    assign midstate_start[6] = 32'hC71636A4;
    assign midstate_start[7] = 32'hDDEF7254;
    
    reg [255:0] sha_start_1d = 0;
    wire [255:0] result;
    
    initial
    begin
        $dumpfile("sha_core_test.vcd");
        $dumpvars(0, uut);
        sha_start_1d = {sha_start[0], sha_start[1], sha_start[2], sha_start[3],
            sha_start[4], sha_start[5], sha_start[6], sha_start[7]};
        #1
        test_message = empty_message;
        clk = 0;
        start = 0;
        $display("Testing empty message:");
        #2 start = 1;
        #5 start = 0;
        #700
        test_message = short_message;
        if (result == 256'he3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855) begin
            $display("PASS");
        end
        else begin
            $display("***FAIL***");
        end
        $display("Testing short message \"abc\":");
        start = 1;
        #10 start = 0;
        #700
        if (result == 256'hba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad) begin
            $display("PASS");
        end
        else begin
            $display("***FAIL***");
        end
        $display("Testing long message \"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnop\"");
        test_message = long_message;
        start = 1;
        #10 start = 0;
        #700
        if (result == 256'haa353e009edbaebfc6e494c8d847696896cb8b398e0173a4b5c1b636292d87c7) begin
            $display("PASS");
        end
        else begin
            $display("***FAIL***");
        end
        $display("Testing outer hash of known solution");
        test_message = hash_message;
        start = 1;
        #10 start = 0;
        #700
        if (result == 256'hd87daf3fc89f293a4c06103a69124c32deb8b3ce97c9c7020000000000000000) begin
            $display("PASS");
        end
        else begin
            $display("***FAIL***");
        end
        $display("Testing inner hash with given midstate",);
        sha_start_1d = {midstate_start[0], midstate_start[1], midstate_start[2], midstate_start[3],
            midstate_start[4], midstate_start[5], midstate_start[6], midstate_start[7]};
        test_message = header_message;
        start = 1;
        #10 start = 0;
        #700
        if (result == 256'h53556ee487598a8944d3bb710913c3211bdd9496f664d723bf0be1926228889f) begin
            $display("PASS");
        end
        else begin
            $display("***FAIL***");
        end
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
        .rst          (1'b1)
    );
endmodule
