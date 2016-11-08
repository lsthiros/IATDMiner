`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/23/2016 08:32:46 PM
// Design Name: 
// Module Name: addrDecoder
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


module addrDecoder(
    inout [7:0] data,
    input [6:0] addr,

    input [7:0]status,
    input [31:0]nonce,
    output [255:0]midstate,
    output [95:0]nextInput,
    output [31:0]difficulty
    );

    // Assumed that addrs 0-4 are read-only. Other register are write-only

    reg writeData = 'd0;
    reg [7:0]dataReg = 'h0;

    reg [7:0]statusReg;
    reg [31:0]nonceReg;
    reg [255:0]midstateReg;
    reg [95:0]nextInputReg;
    reg [31:0]difficultyReg;

    assign data = (writeData == 'd1) ? dataReg : 'bxxxxxxxx;

    assign midstate = midstateReg;
    assign nextInput = nextInputReg;
    assign difficulty = difficultyReg;

    always @(*)
    begin

        if (addr < 'd5)
        begin
            writeData = 'd1;
            
            case (addr)
                'd0: begin
                    statusReg = status;
                    nonceReg = nonce;
                    dataReg = statusReg;
                end
                'd1: dataReg = nonceReg[0:7];
                'd2: dataReg = nonceReg[15:8];
                'd3: dataReg = nonceReg[23:16];
                'd4: dataReg = nonceReg[31:24];
            endcase
        end else
        begin
            writeData = 'd0;
            dataReg = 'd0;

            if (addr < 'd37)
            begin
                midstateReg = (midstateReg & ('hFF << (addr - 'd5))) | (data << (addr - 'd5));
            end else if (addr < 'd49)
            begin
                nextInputReg = (nextInputReg & ('hFF << (addr - 'd37))) | (data << (addr - 'd37));
            end else if (addr < 'd53)
            begin
                difficultyReg = (difficultyReg & ('hFF << (addr - 'd49))) | (data << (addr - 'd49));
            end
        end
    end
    
endmodule
