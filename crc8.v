`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2016 04:57:55 PM
// Design Name: 
// Module Name: designWrapper
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

// Using polynomial 0x83
// Data clock in on falling edge of clock
// Synchronous reset

module crc8 (
    input clk,
    input dataIn,
    input reset,
    output [7:0]msg
    );

    reg [7:0]msgReg = 'd0;
    
    assign msg = msgReg;
    
    always @(negedge clk)
    begin
        if (reset == 'd0)
        begin
            msgReg <= 'd0;
        end else begin
            msgReg[0] <= msgReg[7] ^ dataIn;
            msgReg[1] <= msgReg[7] ^ msgReg[0];
            msgReg[2] <= msgReg[7] ^ msgReg[1];
            msgReg[7:3] <= msgReg[6:2];
        end
    end

endmodule
