// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsha_core__Syms.h"


//======================

void Vsha_core::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vsha_core::traceInit, &Vsha_core::traceFull, &Vsha_core::traceChg, this);
}
void Vsha_core::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vsha_core* t=(Vsha_core*)userthis;
    Vsha_core__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vsha_core::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vsha_core* t=(Vsha_core*)userthis;
    Vsha_core__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vsha_core::traceInitThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vsha_core::traceFullThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vsha_core::traceInitThis__1(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declArray(c+70,"start_state",-1,255,0);
	vcdp->declBit  (c+78,"start",-1);
	vcdp->declBit  (c+79,"clk",-1);
	vcdp->declArray(c+80,"input_message",-1,511,0);
	vcdp->declBit  (c+96,"rst",-1);
	vcdp->declArray(c+97,"result",-1,255,0);
	vcdp->declBit  (c+105,"done",-1);
	vcdp->declArray(c+70,"v start_state",-1,255,0);
	vcdp->declBit  (c+78,"v start",-1);
	vcdp->declBit  (c+79,"v clk",-1);
	vcdp->declArray(c+80,"v input_message",-1,511,0);
	vcdp->declBit  (c+96,"v rst",-1);
	vcdp->declArray(c+97,"v result",-1,255,0);
	vcdp->declBit  (c+105,"v done",-1);
	vcdp->declBit  (c+43,"v state",-1);
	vcdp->declArray(c+44,"v current_state",-1,255,0);
	vcdp->declBus  (c+69,"v round",-1,5,0);
	// Tracing: v message_state // Ignored: Wide memory > --trace-max-array ents at sha_core.v:37
	vcdp->declBus  (c+52,"v round_constant",-1,31,0);
	vcdp->declArray(c+1,"v output_state",-1,255,0);
	vcdp->declBus  (c+9,"v current_message",-1,31,0);
	vcdp->declBus  (c+10,"v word_a",-1,31,0);
	vcdp->declBus  (c+11,"v word_b",-1,31,0);
	vcdp->declBus  (c+12,"v word_c",-1,31,0);
	vcdp->declBus  (c+13,"v word_d",-1,31,0);
	vcdp->declBus  (c+53,"v addr_a",-1,5,0);
	vcdp->declBus  (c+54,"v addr_b",-1,5,0);
	vcdp->declBus  (c+55,"v addr_c",-1,5,0);
	vcdp->declBus  (c+56,"v addr_d",-1,5,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+14+i*1,"v message_chunk",(i+0),31,0);}}
	{int i; for (i=0; i<8; i++) {
		vcdp->declBus  (c+30+i*1,"v combined_result_chunk",(i+0),31,0);}}
	vcdp->declArray(c+106,"v combined_result",-1,255,0);
	// Tracing: v i // Ignored: Verilator trace_off at sha_core.v:59
	vcdp->declBus  (c+69,"v constants round",-1,5,0);
	vcdp->declBus  (c+52,"v constants constant",-1,31,0);
	vcdp->declArray(c+44,"v core_op start_state",-1,255,0);
	vcdp->declBus  (c+52,"v core_op round_constant",-1,31,0);
	vcdp->declBus  (c+9,"v core_op message",-1,31,0);
	vcdp->declArray(c+1,"v core_op result",-1,255,0);
	vcdp->declBus  (c+57,"v core_op a",-1,31,0);
	vcdp->declBus  (c+58,"v core_op b",-1,31,0);
	vcdp->declBus  (c+59,"v core_op c",-1,31,0);
	vcdp->declBus  (c+60,"v core_op d",-1,31,0);
	vcdp->declBus  (c+61,"v core_op e",-1,31,0);
	vcdp->declBus  (c+62,"v core_op f",-1,31,0);
	vcdp->declBus  (c+63,"v core_op g",-1,31,0);
	vcdp->declBus  (c+64,"v core_op h",-1,31,0);
	vcdp->declBus  (c+41,"v core_op a_out",-1,31,0);
	vcdp->declBus  (c+57,"v core_op b_out",-1,31,0);
	vcdp->declBus  (c+58,"v core_op c_out",-1,31,0);
	vcdp->declBus  (c+59,"v core_op d_out",-1,31,0);
	vcdp->declBus  (c+42,"v core_op e_out",-1,31,0);
	vcdp->declBus  (c+61,"v core_op f_out",-1,31,0);
	vcdp->declBus  (c+62,"v core_op g_out",-1,31,0);
	vcdp->declBus  (c+63,"v core_op h_out",-1,31,0);
	vcdp->declBus  (c+65,"v core_op ch",-1,31,0);
	vcdp->declBus  (c+66,"v core_op ma",-1,31,0);
	vcdp->declBus  (c+67,"v core_op sum0",-1,31,0);
	vcdp->declBus  (c+68,"v core_op sum1",-1,31,0);
	vcdp->declBus  (c+38,"v core_op temp",-1,31,0);
	vcdp->declBus  (c+53,"v messages addr_a",-1,5,0);
	vcdp->declBus  (c+54,"v messages addr_b",-1,5,0);
	vcdp->declBus  (c+55,"v messages addr_c",-1,5,0);
	vcdp->declBus  (c+56,"v messages addr_d",-1,5,0);
	vcdp->declBus  (c+69,"v messages round",-1,5,0);
	vcdp->declBus  (c+10,"v messages a",-1,31,0);
	vcdp->declBus  (c+11,"v messages b",-1,31,0);
	vcdp->declBus  (c+12,"v messages c",-1,31,0);
	vcdp->declBus  (c+13,"v messages d",-1,31,0);
	vcdp->declBus  (c+9,"v messages message",-1,31,0);
	vcdp->declBus  (c+39,"v messages s0",-1,31,0);
	vcdp->declBus  (c+40,"v messages s1",-1,31,0);
    }
}

void Vsha_core::traceFullThis__1(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullArray(c+1,(vlTOPp->v__DOT__output_state),256);
	vcdp->fullBus  (c+10,(vlTOPp->v__DOT__word_a),32);
	vcdp->fullBus  (c+11,(vlTOPp->v__DOT__word_b),32);
	vcdp->fullBus  (c+12,(vlTOPp->v__DOT__word_c),32);
	vcdp->fullBus  (c+13,(vlTOPp->v__DOT__word_d),32);
	vcdp->fullBus  (c+14,(vlTOPp->v__DOT__message_chunk[0]),32);
	vcdp->fullBus  (c+15,(vlTOPp->v__DOT__message_chunk[1]),32);
	vcdp->fullBus  (c+16,(vlTOPp->v__DOT__message_chunk[2]),32);
	vcdp->fullBus  (c+17,(vlTOPp->v__DOT__message_chunk[3]),32);
	vcdp->fullBus  (c+18,(vlTOPp->v__DOT__message_chunk[4]),32);
	vcdp->fullBus  (c+19,(vlTOPp->v__DOT__message_chunk[5]),32);
	vcdp->fullBus  (c+20,(vlTOPp->v__DOT__message_chunk[6]),32);
	vcdp->fullBus  (c+21,(vlTOPp->v__DOT__message_chunk[7]),32);
	vcdp->fullBus  (c+22,(vlTOPp->v__DOT__message_chunk[8]),32);
	vcdp->fullBus  (c+23,(vlTOPp->v__DOT__message_chunk[9]),32);
	vcdp->fullBus  (c+24,(vlTOPp->v__DOT__message_chunk[10]),32);
	vcdp->fullBus  (c+25,(vlTOPp->v__DOT__message_chunk[11]),32);
	vcdp->fullBus  (c+26,(vlTOPp->v__DOT__message_chunk[12]),32);
	vcdp->fullBus  (c+27,(vlTOPp->v__DOT__message_chunk[13]),32);
	vcdp->fullBus  (c+28,(vlTOPp->v__DOT__message_chunk[14]),32);
	vcdp->fullBus  (c+29,(vlTOPp->v__DOT__message_chunk[15]),32);
	vcdp->fullBus  (c+30,(vlTOPp->v__DOT__combined_result_chunk[0]),32);
	vcdp->fullBus  (c+31,(vlTOPp->v__DOT__combined_result_chunk[1]),32);
	vcdp->fullBus  (c+32,(vlTOPp->v__DOT__combined_result_chunk[2]),32);
	vcdp->fullBus  (c+33,(vlTOPp->v__DOT__combined_result_chunk[3]),32);
	vcdp->fullBus  (c+34,(vlTOPp->v__DOT__combined_result_chunk[4]),32);
	vcdp->fullBus  (c+35,(vlTOPp->v__DOT__combined_result_chunk[5]),32);
	vcdp->fullBus  (c+36,(vlTOPp->v__DOT__combined_result_chunk[6]),32);
	vcdp->fullBus  (c+37,(vlTOPp->v__DOT__combined_result_chunk[7]),32);
	vcdp->fullBus  (c+38,(vlTOPp->v__DOT__core_op__DOT__temp),32);
	vcdp->fullBus  (c+9,(vlTOPp->v__DOT__current_message),32);
	vcdp->fullBus  (c+39,(((((0xfe000000U & (vlTOPp->v__DOT__word_a 
						 << 0x19U)) 
				 | (0x1ffffffU & (vlTOPp->v__DOT__word_a 
						  >> 7U))) 
				^ ((0xffffc000U & (vlTOPp->v__DOT__word_a 
						   << 0xeU)) 
				   | (0x3fffU & (vlTOPp->v__DOT__word_a 
						 >> 0x12U)))) 
			       ^ (0x1fffffffU & (vlTOPp->v__DOT__word_a 
						 >> 3U)))),32);
	vcdp->fullBus  (c+40,(((((0xffff8000U & (vlTOPp->v__DOT__word_b 
						 << 0xfU)) 
				 | (0x7fffU & (vlTOPp->v__DOT__word_b 
					       >> 0x11U))) 
				^ ((0xffffe000U & (vlTOPp->v__DOT__word_b 
						   << 0xdU)) 
				   | (0x1fffU & (vlTOPp->v__DOT__word_b 
						 >> 0x13U)))) 
			       ^ (0x3fffffU & (vlTOPp->v__DOT__word_b 
					       >> 0xaU)))),32);
	vcdp->fullBus  (c+41,(((vlTOPp->v__DOT__core_op__DOT__temp 
				+ (((vlTOPp->v__DOT__current_state[7U] 
				     & vlTOPp->v__DOT__current_state[6U]) 
				    ^ (vlTOPp->v__DOT__current_state[7U] 
				       & vlTOPp->v__DOT__current_state[5U])) 
				   ^ (vlTOPp->v__DOT__current_state[6U] 
				      & vlTOPp->v__DOT__current_state[5U]))) 
			       + ((((0xc0000000U & 
				     (vlTOPp->v__DOT__current_state[7U] 
				      << 0x1eU)) | 
				    (0x3fffffffU & 
				     (vlTOPp->v__DOT__current_state[7U] 
				      >> 2U))) ^ ((0xfff80000U 
						   & (vlTOPp->v__DOT__current_state[7U] 
						      << 0x13U)) 
						  | (0x7ffffU 
						     & (vlTOPp->v__DOT__current_state[7U] 
							>> 0xdU)))) 
				  ^ ((0xfffffc00U & 
				      (vlTOPp->v__DOT__current_state[7U] 
				       << 0xaU)) | 
				     (0x3ffU & (vlTOPp->v__DOT__current_state[7U] 
						>> 0x16U)))))),32);
	vcdp->fullBus  (c+42,((vlTOPp->v__DOT__current_state[4U] 
			       + vlTOPp->v__DOT__core_op__DOT__temp)),32);
	vcdp->fullBit  (c+43,(vlTOPp->v__DOT__state));
	vcdp->fullArray(c+44,(vlTOPp->v__DOT__current_state),256);
	vcdp->fullBus  (c+53,(vlTOPp->v__DOT__addr_a),6);
	vcdp->fullBus  (c+54,(vlTOPp->v__DOT__addr_b),6);
	vcdp->fullBus  (c+55,(vlTOPp->v__DOT__addr_c),6);
	vcdp->fullBus  (c+56,(vlTOPp->v__DOT__addr_d),6);
	vcdp->fullBus  (c+52,(vlTOPp->v__DOT__round_constant),32);
	vcdp->fullBus  (c+57,(vlTOPp->v__DOT__current_state[7U]),32);
	vcdp->fullBus  (c+58,(vlTOPp->v__DOT__current_state[6U]),32);
	vcdp->fullBus  (c+59,(vlTOPp->v__DOT__current_state[5U]),32);
	vcdp->fullBus  (c+60,(vlTOPp->v__DOT__current_state[4U]),32);
	vcdp->fullBus  (c+61,(vlTOPp->v__DOT__current_state[3U]),32);
	vcdp->fullBus  (c+62,(vlTOPp->v__DOT__current_state[2U]),32);
	vcdp->fullBus  (c+63,(vlTOPp->v__DOT__current_state[1U]),32);
	vcdp->fullBus  (c+64,(vlTOPp->v__DOT__current_state[0U]),32);
	vcdp->fullBus  (c+65,(((vlTOPp->v__DOT__current_state[3U] 
				& vlTOPp->v__DOT__current_state[2U]) 
			       ^ ((~ vlTOPp->v__DOT__current_state[3U]) 
				  & vlTOPp->v__DOT__current_state[1U]))),32);
	vcdp->fullBus  (c+66,((((vlTOPp->v__DOT__current_state[7U] 
				 & vlTOPp->v__DOT__current_state[6U]) 
				^ (vlTOPp->v__DOT__current_state[7U] 
				   & vlTOPp->v__DOT__current_state[5U])) 
			       ^ (vlTOPp->v__DOT__current_state[6U] 
				  & vlTOPp->v__DOT__current_state[5U]))),32);
	vcdp->fullBus  (c+67,(((((0xc0000000U & (vlTOPp->v__DOT__current_state[7U] 
						 << 0x1eU)) 
				 | (0x3fffffffU & (
						   vlTOPp->v__DOT__current_state[7U] 
						   >> 2U))) 
				^ ((0xfff80000U & (
						   vlTOPp->v__DOT__current_state[7U] 
						   << 0x13U)) 
				   | (0x7ffffU & (vlTOPp->v__DOT__current_state[7U] 
						  >> 0xdU)))) 
			       ^ ((0xfffffc00U & (vlTOPp->v__DOT__current_state[7U] 
						  << 0xaU)) 
				  | (0x3ffU & (vlTOPp->v__DOT__current_state[7U] 
					       >> 0x16U))))),32);
	vcdp->fullBus  (c+68,(((((0xfc000000U & (vlTOPp->v__DOT__current_state[3U] 
						 << 0x1aU)) 
				 | (0x3ffffffU & ((
						   vlTOPp->v__DOT__current_state[4U] 
						   << 0x1aU) 
						  | (vlTOPp->v__DOT__current_state[3U] 
						     >> 6U)))) 
				^ ((0xffe00000U & (
						   vlTOPp->v__DOT__current_state[3U] 
						   << 0x15U)) 
				   | (0x1fffffU & (
						   (vlTOPp->v__DOT__current_state[4U] 
						    << 0x15U) 
						   | (vlTOPp->v__DOT__current_state[3U] 
						      >> 0xbU))))) 
			       ^ ((0xffffff80U & (vlTOPp->v__DOT__current_state[3U] 
						  << 7U)) 
				  | (0x7fU & ((vlTOPp->v__DOT__current_state[4U] 
					       << 7U) 
					      | (vlTOPp->v__DOT__current_state[3U] 
						 >> 0x19U)))))),32);
	vcdp->fullBus  (c+69,(vlTOPp->v__DOT__round),6);
	vcdp->fullArray(c+70,(vlTOPp->start_state),256);
	vcdp->fullBit  (c+78,(vlTOPp->start));
	vcdp->fullBit  (c+79,(vlTOPp->clk));
	vcdp->fullArray(c+80,(vlTOPp->input_message),512);
	vcdp->fullBit  (c+96,(vlTOPp->rst));
	vcdp->fullArray(c+97,(vlTOPp->result),256);
	vcdp->fullBit  (c+105,(vlTOPp->done));
	vcdp->fullArray(c+106,(vlTOPp->v__DOT__combined_result),256);
    }
}
