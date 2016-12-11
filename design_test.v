`timescale 1ns / 1ps
module design_test (
);

reg clk = 0;
reg sclk = 0;
reg mosi = 0;
reg cs = 1;
reg reset = 1;
reg shaReset = 1;


wire miso;
wire [3:0]bitCountOut;
wire resOut;
wire solutionFound;



designWrapper dw (
    .CLK100MHZ(clk),
    .sclk(sclk),
    .miso(miso),
    .mosi(mosi),
    .cs(cs),
    .reset(reset),
    .shaReset(shaReset),
    .bitCount(bitCountOut),
    .resOut(resOut),
    .solutionFound(solutionFound)
    );

always
begin
    #1 clk = !clk;
end

task rw_bit;
input wBit;
output rBit;
begin
    #50
    sclk = 'd1;
    mosi = wBit;
    #50
    rBit = miso;
    sclk = 'd0;
end
endtask

task rw_byte;
input [7:0]wByte;
output [7:0]rByte;
integer i;
begin
    i = 0;
    for (i = 0; i < 8; i = i + 1)
    begin
        rw_bit(wByte[7 - i], rByte[7 - i]);
    end
end
endtask

task read_state;
output [7:0]state;
reg [7:0]dummy;
begin
    dummy = 'd0;
    rw_byte(dummy, state);
end
endtask

task read_nonce;
output [31:0]nonce;
reg [7:0]dummy;
begin
    dummy = 'd0;
    rw_byte(dummy, nonce[31:24]);
    rw_byte(dummy, nonce[23:16]);
    rw_byte(dummy, nonce[15:8]);
    rw_byte(dummy, nonce[7:0]);
end
endtask

task reset_sha;
input dummy;
begin
    #50
    shaReset = 'd1;
    #50
    shaReset = 'd0;
    #50
    shaReset = 'd1;
end
endtask

task rw_midstate;
input [255:0]wMidstate;
output [255:0]rMidstate;
integer idx;
reg [255:0]temp;
begin
    idx = 0;
    temp = wMidstate;
    for (idx = 0; idx < 32; idx = idx + 1)
    begin
        rMidstate = rMidstate << 8;
        rw_byte(temp[7:0], rMidstate[7:0]);
        temp = temp >> 8;
    end
end
endtask

task rw_header;
input [95:0]wHeader;
output [95:0]rHeader;
integer idx;
reg [95:0]temp;
begin
    idx = 0;
    temp = wHeader;
    for (idx = 0; idx < 12; idx = idx + 1)
    begin
        rHeader = rHeader << 8;
        rw_byte(temp[7:0], rHeader[7:0]);
        temp = temp >> 8;
    end
end
endtask

task rw_target;
input [255:0]wTarget;
output [255:0]rTarget;
integer idx;
reg [255:0]temp;
begin
    idx = 0;
    temp = wTarget;
    for (idx = 0; idx < 32; idx = idx + 1)
    begin
        rTarget = rTarget << 8;
        rw_byte(temp[7:0], rTarget[7:0]);
        temp = temp >> 8;
    end
end
endtask


reg [31:0]nonce;
reg [7:0]state;
reg [255:0]midstate = 256'h4a03aeb2bcf3ad77d705828c4ec62fa2282784a285936a72c71636a4ddef7254;
reg [255:0] target = 256'h00000000000000000440C4000000000000000000000000000000000000000000;
reg [95:0] header_leftovers = 96'h15274c646c51f957c4400418;

reg [255:0]rMidstate;
reg [255:0]rTarget;
reg [255:0]rHeader;

initial begin


    #3000
    cs = 'd0;
    #100

    read_state(state);
    read_nonce(nonce);
    
    rw_midstate(midstate, rMidstate);
    rw_header(header_leftovers, rHeader);
    rw_target(target, rTarget);


    #100
    cs = 'd1;

    reset_sha('d0);

    // Enough time for the solution to be found
    #3000

    cs = 'd0;
    #100
    
    read_state(state);
    read_nonce(nonce);
    #100
    cs = 'd1;

    if (state == 'd2)
    begin
        $display("Pass: State finished");
    
        if (nonce == 'h9c9a4fcb)
        begin
            $display("Pass: Nonce correct");
        end
        else begin
            $display("Fail: Nonce incorrect");
        end
    end
    else begin
        $display("Fail: State did not finish");
    end

    $finish;
end

endmodule

