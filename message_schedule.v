`timescale 1ns / 1ps


/* A simultaneous round => address decoder and a past-message => current
 * message encoder. It should probably be separated into those two components
 */
module message_schedule(addr_a, addr_b, addr_c, addr_d, a, b, c, d, round, message);
output [5:0] addr_a;
output [5:0] addr_b;
output [5:0] addr_c;
output [5:0] addr_d;
input [5:0] round;
input [31:0] a;
input [31:0] b;
input [31:0] c;
input [31:0] d;
output [31:0] message;

wire [31:0] s0;
wire [31:0] s1;

assign s0 = {a[6:0], a[31:7]} ^ {a[17:0], a[31:18]} ^ {3'b0, a[31:3]};
assign s1 = {b[16:0], b[31:17]} ^ {b[18:0], b[31:19]} ^ {10'b0, b[31:10]};

assign addr_a = (round < 6'd16) ? round : round - 15;
assign addr_b = round - 2;
assign addr_c = round - 16;
assign addr_d = round - 7;

assign message = (round < 16) ? a : c + s0 + d + s1;

endmodule
