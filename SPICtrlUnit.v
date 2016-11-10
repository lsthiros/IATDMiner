`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/27/2016 07:46:28 PM
// Design Name: 
// Module Name: SPICtrlUnit
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


module SPICtrlUnit(
    input clk,
    input byteRead,
    input chipSelect,
    output writeReg,
    output writeShiftReg,
    output [6:0] regNum,
    output registersValid
    );

    parameter CtrlStateWait = 'd0,
              CtrlStateWriteReg1 = 'd1,
              CtrlStateWriteReg2 = 'd2,
              CtrlStateIncRegnum = 'd3,
              CtrlStateWriteShiftReg1 = 'd4,
              CtrlStateWriteShiftReg2 = 'd5,
              CtrlStateWaitNextByte = 'd6;

    parameter MaxReadSpiRegNum = 'd5,
              MaxSpiRegNum = 'd10;

    parameter RegValidStateInvalid = 'd0,
              RegValidStateValid = 'd1;
              
    reg [7:0]ctrlState = CtrlStateWait;
    reg [7:0]nextState = CtrlStateWait;
    reg regValidState = RegValidStateInvalid;

    reg [6:0]spiRegNum = 'd0;
    reg writeRegReg = 'd0;
    reg writeShiftRegReg = 'd0;

    assign registersValid = (regValidState == RegValidStateValid) ? 'd1 : 'd0;
    assign regNum = spiRegNum;
    assign writeReg = writeRegReg;
    assign writeShiftReg = writeShiftRegReg;

    always @(posedge clk)
    begin
        ctrlState <= nextState;

        if (chipSelect == 'd1)
        begin
            spiRegNum <= 'd0;
        end else begin
            if (ctrlState == CtrlStateIncRegnum)
            begin
                spiRegNum <= spiRegNum + 'd1;

                if (spiRegNum >= MaxSpiRegNum)
                begin
                    regValidState <= RegValidStateValid;
                end else if (spiRegNum > MaxReadSpiRegNum)
                begin
                    regValidState <= RegValidStateInvalid;
                end

            end else
            begin
                spiRegNum <= spiRegNum;
            end
        end
    end

    always @(*)
    begin
        if (chipSelect == 'd1)
        begin
            nextState <= CtrlStateWriteShiftReg1;

            writeShiftRegReg <= 'd0;
            writeRegReg <= 'd0;
        end else begin

            case (ctrlState)
                CtrlStateWait:
                begin
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd0;
                    if (byteRead == 'd1)
                    begin
                        nextState <= CtrlStateWriteReg1;
                    end else begin
                        nextState <= CtrlStateWait;
                    end
                end

                CtrlStateWriteReg1:
                begin
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd1;
                    nextState <= CtrlStateWriteReg2;
                end
                
                CtrlStateWriteReg2:
                begin
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd1;
                    nextState <= CtrlStateIncRegnum;
                end

                CtrlStateIncRegnum:
                begin
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd0;
                    nextState <= CtrlStateWriteShiftReg1;
                end

                CtrlStateWriteShiftReg1:
                begin
                    writeShiftRegReg <= 'd1;
                    writeRegReg <= 'd0;
                    nextState <= CtrlStateWriteShiftReg2;
                end

                CtrlStateWriteShiftReg2:
                begin
                    writeShiftRegReg <= 'd1;
                    writeRegReg <= 'd0;
                    nextState <= CtrlStateWaitNextByte;
                end

                CtrlStateWaitNextByte:
                begin
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd0;
                    
                    if (byteRead == 'd1)
                    begin
                        nextState <= CtrlStateWaitNextByte;
                    end else begin
                        nextState <= CtrlStateWait;
                    end
                end
                default:
                begin
                    nextState <= CtrlStateWait;
                    writeShiftRegReg <= 'd0;
                    writeRegReg <= 'd0;
                end
            endcase
        end
    end

endmodule
