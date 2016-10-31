`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:  
// Engineer: 
// 
// Create Date: 09/11/2016 08:49:10 PM
// Design Name: 
// Module Name: sha_core
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


module sha_core(
    input [255:0] start_state,
    input start,
    input clk,
    input [511:0] input_message,
    input rst,
    output [255:0] result,
    output done
    );
    
    reg state;
    reg [255:0] current_state;
    reg [5:0] round;
    
    reg [31:0] message_state [0:15];
    
    wire [31:0] round_constant;
    wire [255:0] output_state;
    wire [31:0] current_message;
    
    wire [31:0] word_a;
    wire [31:0] word_b;
    wire [31:0] word_c;
    wire [31:0] word_d;
    
    wire [5:0] addr_a;
    wire [5:0] addr_b;
    wire [5:0] addr_c;
    wire [5:0] addr_d;
    
    wire [31:0] message_chunk [0:15];
    
    wire [31:0] combined_result_chunk [0:7];
    wire [255:0] combined_result;
    
    generate
    genvar i;
    for (i = 0; i < 16; i=i+1) assign message_chunk[i] = input_message[511 - i * 32: 512 - (i + 1) * 32];
    for (i = 0; i < 8; i=i+1)
    begin
        assign combined_result_chunk[i] = output_state[255 - i * 32: 256 - (i + 1) * 32] + start_state[255 - i * 32: 256 - (i + 1) * 32];
        assign result[255 - i * 32: 256 - (i + 1) * 32] = combined_result_chunk[i];
    end
    endgenerate
    
    assign word_a = (addr_a < 16) ? message_chunk[addr_a[3:0]] : message_state[addr_a[3:0]];
    assign word_b = (addr_b < 16) ? message_chunk[addr_b[3:0]] : message_state[addr_b[3:0]];
    assign word_c = (addr_c < 16) ? message_chunk[addr_c[3:0]] : message_state[addr_c[3:0]];
    assign word_d = (addr_d < 16) ? message_chunk[addr_d[3:0]] : message_state[addr_d[3:0]];
    
    assign done = (round == 6'b111111) ? 1 : 0;
    
    k_table constants (
        .round (round),
        .constant (round_constant)
    );
    
    sha_round core_op (
        .start_state (current_state),
        .result (output_state),
        .round_constant (round_constant),
        .message (current_message)
    );
    
    message_schedule messages (
        .addr_a (addr_a),
        .addr_b (addr_b),
        .addr_c (addr_c),
        .addr_d (addr_d),
        .a (word_a),
        .b (word_b),
        .c (word_c),
        .d (word_d),
        .message (current_message),
        .round(round)
    );
    
    initial
    begin
    state = 0;
    current_state = 0;
    end
    
    always @ (posedge clk)
    begin
        if (!rst) begin
            state <= 0;
            current_state <= 0;
        end
        else begin
            case (state)
                // idle
                1'b0 : begin
                    if (start) begin
                        state <= 1;
                        current_state <= start_state;
                        round <= 0;
                    end
                end
                // work on hashing
                1'b1 : begin
                    if (round == 6'b111111) begin
                        state <= 0;
                    end
                    else
                    begin
                        current_state <= output_state;
                        round <= round + 1;
                        if (round >= 16) begin
                            message_state[round[3:0]] <= current_message;
                        end
                    end
                end
            endcase
        end
    end
endmodule
