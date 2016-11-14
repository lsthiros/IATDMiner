`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2016 04:29:20 PM
// Design Name: 
// Module Name: regFile
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


module regFile(
    input clk,
    input reset,
    input [6:0] regANum,
    output [7:0] regAOut,
    input writeA,
    input [7:0] inA,

    input [2:0] state_in,
    input [31:0] nonce,
    output [255:0] midstate,
    output [95:0] header_leftovers,
    output [255:0] target
    );

    reg [31:0]nonceBuffer;

    reg [7:0]registers[75:0];

    reg [7:0]regAOutReg = 'd0;
    reg [7:0]regBOutReg = 'd0;

    assign regAOut = regAOutReg;
    assign midstate = {
        registers[31], registers[30], 
        registers[29], registers[28], registers[27], registers[26], registers[25],
        registers[24], registers[23], registers[22], registers[21], registers[20],
        registers[19], registers[18], registers[17], registers[16], registers[15],
        registers[14], registers[13], registers[12], registers[11], registers[10],
        registers[9], registers[8], registers[7], registers[6], registers[5],
        registers[4], registers[3], registers[2], registers[1], registers[0]
        };

    assign header_leftovers = {
        registers[43], registers[42], registers[41], registers[40],
        registers[39], registers[38], registers[37], registers[36], registers[35],
        registers[34], registers[33], registers[32]
        };

    assign target = {

        registers[75],
        registers[74], registers[73], registers[72], registers[71], registers[70],
        registers[69], registers[68], registers[67], registers[66], registers[65],
        registers[64], registers[63], registers[62], registers[61], registers[60],
        registers[59], registers[58], registers[57], registers[56], registers[55],
        registers[54], registers[53], registers[52], registers[51], registers[50],
        registers[49], registers[48], registers[47], registers[46], registers[45],
        registers[44]
        };

    always @(*)
    begin
        nonceBuffer = nonceBuffer;
        if (regANum >= 'd10)
        begin
            regAOutReg = 'd0;
        end else if (regANum == 'd0) begin
            regAOutReg = {5'd0, state_in};
        end else if (regANum == 'd1) begin
            nonceBuffer = nonce;
            regAOutReg = nonceBuffer[31:24];
        end else if (regANum == 'd2) begin
            regAOutReg = nonceBuffer[23:16];
        end else if (regANum == 'd3) begin
            regAOutReg = nonceBuffer[15:8];
        end else if (regANum == 'd4) begin
            regAOutReg = nonceBuffer[7:0];
        end else begin
            regAOutReg = registers[regANum - 'd5];
        end
    end

    integer i;

    always @(posedge clk)
    begin
        if (writeA == 'd1)
        begin
            if (regANum >= 'd5)
            begin
                registers[regANum - 'd5] = inA;
            end
        end

        if (reset == 'd0)
        begin
            for (i = 0; i < 76; i = i + 1)
            begin
                registers[i] = 'd0;
            end
        end
    end
    
endmodule
