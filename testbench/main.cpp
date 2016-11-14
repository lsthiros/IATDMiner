#include "Vsha_core.h"

#include <verilated.h>
#include <verilated_vcd_c.h>

#include <stdint.h>
#include <string.h>

const uint32_t start_states[] = {
	0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

int main(int argc, char **argv, char **env) {
    int i;
    int clk;
    Verilated::commandArgs(argc, argv);

    uint32_t *word_index;

    Vsha_core *top = new Vsha_core;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("sha_core.vcd");

    word_index = top->start_state;
    for (i = 0; i < 8; i++) {
    	*word_index = start_states[7 - i];
    	word_index++;
    }

    memset(top->input_message, 0, sizeof(uint8_t) * 64);
    ((uint8_t*)(top->input_message))[63] = 0x80;
    top->clk = 1;
    top->start = 0;
    top->rst = 1;

    for (i = 0; i < 256; i++) {
    	for (clk = 0; clk < 2; clk++) {
    		top->start = (i == 3);
    		tfp->dump(2 * i + clk);
    		top->clk = !top->clk;
    		top->eval();
    	}
    }

    tfp->close();
    return 0;
}
