`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/22/2016 07:53:08 PM
// Design Name: 
// Module Name: shiftRegister
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

// MSB First
// Data clocked on falling edge
// Data out bit changes on rising edge (CPHA = 1, CPOL = 0)
// Active low sync reset
// 8-bit input & output ports
// Active low writeClk sync writeP

module shiftRegister(
    input sclk,
    input writeClk,
    input reset,
    input dIn,
    input [7:0] pIn,
    input writeP,
    output dOut,
    output [7:0] pOut
    );
    
    parameter StateWaitForHigh = 'd0,
              StateWaitForFalling = 'd1;

    reg [7:0]internal = 'd0;
    reg [7:0]pReg = 'd0;
    reg dOutReg = 'd0;
    reg srState = StateWaitForHigh;

    assign pOut = internal;
    assign dOut = dOutReg;

    always @(negedge writeClk)
    begin
        if (reset == 'd0)
        begin
            srState <= StateWaitForHigh;

            internal <= 'd0;
            dOutReg <= 'd0;
        end else if (writeP == 'd1)
        begin
            internal[7:0] <= pIn;
            dOutReg <= 'd0;

            if (sclk == 'd0)
            begin
                srState <= StateWaitForHigh;
            end else
            begin
                srState <= StateWaitForFalling;
            end
        end else 
        begin
            if (srState == StateWaitForHigh)
            begin
                if (sclk == 'd0)
                begin
                    srState <= StateWaitForHigh;

                    dOutReg <= dOutReg;
                end else begin
                    srState <= StateWaitForFalling;

                    dOutReg <= internal[7];
                end

                internal <= internal;
            end else
            begin
                if (sclk == 'd0)
                begin
                    internal <= {internal[7:0], dIn};

                    srState <= StateWaitForHigh;
                end else begin
                    internal <= internal;

                    srState <= StateWaitForFalling;
                end

                dOutReg <= dOutReg;
            end
        end

        /*
        if (clk == 'd0)
        begin
            if (reset == 'd0)
            begin
                internal <= 'd0;
            end else
            begin
                internal <= {internal[7:0], dIn};
            end
        end else begin
            if (writeP == 'd1)
            begin
                internal[7:0] <= pIn;
            end else
            begin
                internal <= internal;
            end
        end
        */
    end

    /*
    always @(posedge clk)
    begin
        dOutReg = internal[7];
    end
    
    always @(negedge writeClk)
    begin
        if (writeP == 'd1)
        begin
            internal = pIn;
        end
    end
    */


endmodule
