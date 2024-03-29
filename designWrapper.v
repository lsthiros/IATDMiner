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


module designWrapper(
    input CLK100MHZ,
    input sclk,
    output miso,
    input mosi,
    input cs,
    input reset,
    input shaReset,
    output [3:0]bitCount,
    output resOut,
    output solutionFound
    );
    
    wire [7:0]spiInputData;
    wire [7:0]spiOutputData;
    wire registerValid;
    wire regFileWrite;
    wire [6:0]regFileNum;

    wire sclkFilterd;

    reg [6:0]regBNum = 'd0;
    wire [7:0]regBOut;

    reg spiClock = 'd0;
    reg [15:0]spiClkCounter = 'd0;

    (* mark_debug = "true" *) wire [255:0] midstate;
    (* mark_debug = "true" *) wire [95:0] header_leftovers;
    (* mark_debug = "true" *) wire [255:0] target;
    (* mark_debug = "true" *) wire [2:0] shaState;
    (* mark_debug = "true" *) wire [31:0] nonce;

    //(* mark_debug = "true" *) wire [255:0] midstate;
    //(* mark_debug = "true" *) wire [95:0] header_leftovers;
    //(* mark_debug = "true" *) wire [255:0] target;
    //(* mark_debug = "true" *) wire [2:0] shaState;
    //(* mark_debug = "true" *) wire [31:0] nonce;
    
    reg [32:0] my_nonce;

    assign resOut = reset;

    assign solutionFound = shaState[2];
    
    inputFilter sclkFilter (
        .clk(CLK100MHZ),
        .inData(sclk),
        .outData(sclkFiltered)
    );

    spiHw spi (
        .clk(CLK100MHZ),
        .reset(reset),
        .sclk(sclkFiltered),
        .miso(miso),
        .mosi(mosi),
        .cs(cs),
        .inData(spiInputData),
        .outData(spiOutputData),
        .valid(registersValid),
        .writeReg(regFileWrite),
        .regNum(regFileNum),
        .bitCount(bitCount)
    );

    regFile regFile (
        .clk(CLK100MHZ),
        .reset(reset),
        .regANum(regFileNum),
        .regAOut(spiInputData),
        .writeA(regFileWrite),
        .inA(spiOutputData),
        .state_in(shaState),
        .nonce(nonce),
        .midstate(midstate),
        .header_leftovers(header_leftovers),
        .target(target)
    );

    block_solver solver (
        .clk(CLK100MHZ),
        .rst_n(shaReset),
        .midstate(midstate),
        .header_leftovers(header_leftovers),
        .target(target),
        .state_out(shaState),
        .current_nonce(nonce)
    );

    /*
    vio_0 debugCore (
        .clk(slowClk),
        .probe_in0(midstate),
        .probe_in1(header_leftovers),
        .probe_in2(target),
        .probe_in3(nonce)
    );
    */

endmodule
