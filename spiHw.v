`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/22/2016 09:30:54 PM
// Design Name: 
// Module Name: spiHw
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


module spiHw(
    input clk,  // Clock
    input reset,
    input sclk, // SPI Clock Input
    output miso,
    input mosi,
    input cs,
    input [7:0] inData,
    output [7:0] outData,
    output valid,
    output writeReg,
    output [6:0]regNum,
    output [3:0]bitCount
    );

    wire writePWire;
    wire dOutWire;
    wire counterClkGated;
   
    wire counterResetWire;

    reg [3:0]bitCounterReg = 'd0;
    reg oldSclk;

    assign bitCount = bitCounterReg;
    
    shiftRegister sr (
        .sclk(sclk),
        .writeClk(clk),
        .reset(reset),
        .dIn(mosi),
        .pIn(inData),
        .writeP(writePWire),
        .dOut(dOutWire),
        .pOut(outData)
    );

    SPICtrlUnit ctrlUnit (
        .clk(clk),
        .byteRead(bitCounterReg[3]),
        .chipSelect(cs),
        .writeReg(writeReg),
        .writeShiftReg(writePWire),
        .regNum(regNum),
        .registersValid(valid)
    );

    // Only output when cs is low
    assign miso = dOutWire;

    // Write the new output byte into the shift register after
    // writing the old value to a register
    // assign writePWire = bitCounterReg[3] & (~writeReg);

    assign counterResetWire = sclk & bitCounterReg[3];
    
    /*
    // On negedge of chip select reset bitCounter
    always @(negedge cs)
    begin
        bitCounterReg = 'd0;
    end

    // On the beginning of a new byte reset bitCounter
    always @(posedge counterResetWire)
    begin
        bitCounterReg = 'd0;
    end
    */

    // Increase the bit count on the negative sclk edge
    always @(posedge clk)
    begin
        if (cs == 'd1)
        begin
            bitCounterReg <= 'd0;
        end else if (sclk == 'd0 && oldSclk == 'd1)
        begin
            if (bitCounterReg == 'd8)
            begin
                bitCounterReg <= 'd1;
            end else
            begin
                bitCounterReg <= bitCounterReg + 'd1;
            end
        end else begin
            bitCounterReg <= bitCounterReg;
        end

        oldSclk <= sclk;
    end




endmodule
