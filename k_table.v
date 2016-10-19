`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/11/2016 05:18:21 PM
// Design Name: 
// Module Name: k_table
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


/* LUT for the SHA 256 round constants. Each round corresponds to a constant
 * specified as the first 32 bits of the fractional parts of the cube root of
 * the first 64 primes. Generated with a python script.
 */
module k_table(
    input [5:0] round,
    output reg [31:0] constant
    );
    
    always @*
    begin
    case (round)
        6'h00 : constant = 32'h428a2f98;
        6'h01 : constant = 32'h71374491;
        6'h02 : constant = 32'hb5c0fbcf;
        6'h03 : constant = 32'he9b5dba5;
        6'h04 : constant = 32'h3956c25b;
        6'h05 : constant = 32'h59f111f1;
        6'h06 : constant = 32'h923f82a4;
        6'h07 : constant = 32'hab1c5ed5;
        6'h08 : constant = 32'hd807aa98;
        6'h09 : constant = 32'h12835b01;
        6'h0a : constant = 32'h243185be;
        6'h0b : constant = 32'h550c7dc3;
        6'h0c : constant = 32'h72be5d74;
        6'h0d : constant = 32'h80deb1fe;
        6'h0e : constant = 32'h9bdc06a7;
        6'h0f : constant = 32'hc19bf174;
        6'h10 : constant = 32'he49b69c1;
        6'h11 : constant = 32'hefbe4786;
        6'h12 : constant = 32'h0fc19dc6;
        6'h13 : constant = 32'h240ca1cc;
        6'h14 : constant = 32'h2de92c6f;
        6'h15 : constant = 32'h4a7484aa;
        6'h16 : constant = 32'h5cb0a9dc;
        6'h17 : constant = 32'h76f988da;
        6'h18 : constant = 32'h983e5152;
        6'h19 : constant = 32'ha831c66d;
        6'h1a : constant = 32'hb00327c8;
        6'h1b : constant = 32'hbf597fc7;
        6'h1c : constant = 32'hc6e00bf3;
        6'h1d : constant = 32'hd5a79147;
        6'h1e : constant = 32'h06ca6351;
        6'h1f : constant = 32'h14292967;
        6'h20 : constant = 32'h27b70a85;
        6'h21 : constant = 32'h2e1b2138;
        6'h22 : constant = 32'h4d2c6dfc;
        6'h23 : constant = 32'h53380d13;
        6'h24 : constant = 32'h650a7354;
        6'h25 : constant = 32'h766a0abb;
        6'h26 : constant = 32'h81c2c92e;
        6'h27 : constant = 32'h92722c85;
        6'h28 : constant = 32'ha2bfe8a1;
        6'h29 : constant = 32'ha81a664b;
        6'h2a : constant = 32'hc24b8b70;
        6'h2b : constant = 32'hc76c51a3;
        6'h2c : constant = 32'hd192e819;
        6'h2d : constant = 32'hd6990624;
        6'h2e : constant = 32'hf40e3585;
        6'h2f : constant = 32'h106aa070;
        6'h30 : constant = 32'h19a4c116;
        6'h31 : constant = 32'h1e376c08;
        6'h32 : constant = 32'h2748774c;
        6'h33 : constant = 32'h34b0bcb5;
        6'h34 : constant = 32'h391c0cb3;
        6'h35 : constant = 32'h4ed8aa4a;
        6'h36 : constant = 32'h5b9cca4f;
        6'h37 : constant = 32'h682e6ff3;
        6'h38 : constant = 32'h748f82ee;
        6'h39 : constant = 32'h78a5636f;
        6'h3a : constant = 32'h84c87814;
        6'h3b : constant = 32'h8cc70208;
        6'h3c : constant = 32'h90befffa;
        6'h3d : constant = 32'ha4506ceb;
        6'h3e : constant = 32'hbef9a3f7;
        default: constant = 32'hc67178f2;
endcase
end
endmodule
