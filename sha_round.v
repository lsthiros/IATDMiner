`timescale 1ns / 1ps

module sha_round(start_state, round_constant, message, result);

input [255:0] start_state;
input [31:0] round_constant;
input [31:0] message;
output [255:0] result;

wire [31:0] a;
wire [31:0] b;
wire [31:0] c;
wire [31:0] d;
wire [31:0] e;
wire [31:0] f;
wire [31:0] g;
wire [31:0] h;

wire [31:0] a_out;
wire [31:0] b_out;
wire [31:0] c_out;
wire [31:0] d_out;
wire [31:0] e_out;
wire [31:0] f_out;
wire [31:0] g_out;
wire [31:0] h_out;

wire [31:0]ch;
wire [31:0]ma;
wire [31:0]sum0;
wire [31:0]sum1;

wire [31:0] temp;

assign a = start_state[255:224];
assign b = start_state[223:192];
assign c = start_state[191:160];
assign d = start_state[159:128];
assign e = start_state[127:96];
assign f = start_state[95:64];
assign g = start_state[63:32];
assign h = start_state[31:0];

assign ch = (e & f) ^ (~e & g);
assign ma = (a & b) ^ (a & c) ^ (b & c);

assign sum0 = {a[1:0], a[31:2]} ^ {a[12:0], a[31:13]} ^ {a[21:0], a[31:22]};
assign sum1 = {e[5:0], e[31:6]} ^ {e[10:0], e[31:11]} ^ {e[24:0], e[31:25]};

assign temp = h + round_constant + message + ch + sum1;

assign a_out = temp + ma + sum0;
assign b_out = a;
assign c_out = b;
assign d_out = c;
assign e_out = d + temp;
assign f_out = e;
assign g_out = f;
assign h_out = g;

assign result = {a_out, b_out, c_out, d_out, e_out, f_out, g_out, h_out};

endmodule