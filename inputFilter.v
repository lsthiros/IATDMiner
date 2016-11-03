`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/10/2016 08:58:05 PM
// Design Name: 
// Module Name: inputFilter
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

// Three point input filter. Last three readings must agree in order to switch
// state

module inputFilter(
    input clk,
    input inData,
    input outData
    );

    parameter StateZero = 'd0,
              StateOne  = 'd1;

    reg [1:0]lastPoints = 'd0;
    reg currState = StateZero;
    reg nextState = StateZero;

    assign outData = (currState == StateZero) ? 'd0 : 'd1;
    
    always @(*)
    begin
        if (lastPoints[0] == 'd0 &&
            lastPoints[1] == 'd0 &&
            inData == 'd0)
        begin
            nextState <= StateZero;
        end
        else if (lastPoints[0] == 'd1 &&
                 lastPoints[1] == 'd1 &&
                 inData == 'd1)
        begin
            nextState <= StateOne;
        end else begin
            nextState <= currState;
        end
    end

    always @(negedge clk)
    begin
        currState <= nextState;

        lastPoints[1] <= lastPoints[0];
        lastPoints[0] <= inData;
    end

endmodule
