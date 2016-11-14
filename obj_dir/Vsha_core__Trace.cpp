// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsha_core__Syms.h"


//======================

void Vsha_core::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vsha_core* t=(Vsha_core*)userthis;
    Vsha_core__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vsha_core::traceChgThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vsha_core::traceChgThis__2(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+1,(vlTOPp->v__DOT__output_state),256);
	vcdp->chgBus  (c+10,(vlTOPp->v__DOT__word_a),32);
	vcdp->chgBus  (c+11,(vlTOPp->v__DOT__word_b),32);
	vcdp->chgBus  (c+12,(vlTOPp->v__DOT__word_c),32);
	vcdp->chgBus  (c+13,(vlTOPp->v__DOT__word_d),32);
	vcdp->chgBus  (c+14,(vlTOPp->v__DOT__message_chunk[0]),32);
	vcdp->chgBus  (c+15,(vlTOPp->v__DOT__message_chunk[1]),32);
	vcdp->chgBus  (c+16,(vlTOPp->v__DOT__message_chunk[2]),32);
	vcdp->chgBus  (c+17,(vlTOPp->v__DOT__message_chunk[3]),32);
	vcdp->chgBus  (c+18,(vlTOPp->v__DOT__message_chunk[4]),32);
	vcdp->chgBus  (c+19,(vlTOPp->v__DOT__message_chunk[5]),32);
	vcdp->chgBus  (c+20,(vlTOPp->v__DOT__message_chunk[6]),32);
	vcdp->chgBus  (c+21,(vlTOPp->v__DOT__message_chunk[7]),32);
	vcdp->chgBus  (c+22,(vlTOPp->v__DOT__message_chunk[8]),32);
	vcdp->chgBus  (c+23,(vlTOPp->v__DOT__message_chunk[9]),32);
	vcdp->chgBus  (c+24,(vlTOPp->v__DOT__message_chunk[10]),32);
	vcdp->chgBus  (c+25,(vlTOPp->v__DOT__message_chunk[11]),32);
	vcdp->chgBus  (c+26,(vlTOPp->v__DOT__message_chunk[12]),32);
	vcdp->chgBus  (c+27,(vlTOPp->v__DOT__message_chunk[13]),32);
	vcdp->chgBus  (c+28,(vlTOPp->v__DOT__message_chunk[14]),32);
	vcdp->chgBus  (c+29,(vlTOPp->v__DOT__message_chunk[15]),32);
	vcdp->chgBus  (c+30,(vlTOPp->v__DOT__combined_result_chunk[0]),32);
	vcdp->chgBus  (c+31,(vlTOPp->v__DOT__combined_result_chunk[1]),32);
	vcdp->chgBus  (c+32,(vlTOPp->v__DOT__combined_result_chunk[2]),32);
	vcdp->chgBus  (c+33,(vlTOPp->v__DOT__combined_result_chunk[3]),32);
	vcdp->chgBus  (c+34,(vlTOPp->v__DOT__combined_result_chunk[4]),32);
	vcdp->chgBus  (c+35,(vlTOPp->v__DOT__combined_result_chunk[5]),32);
	vcdp->chgBus  (c+36,(vlTOPp->v__DOT__combined_result_chunk[6]),32);
	vcdp->chgBus  (c+37,(vlTOPp->v__DOT__combined_result_chunk[7]),32);
	vcdp->chgBus  (c+38,(vlTOPp->v__DOT__core_op__DOT__temp),32);
	vcdp->chgBus  (c+9,(vlTOPp->v__DOT__current_message),32);
	vcdp->chgBus  (c+39,(((((0xfe000000U & (vlTOPp->v__DOT__word_a 
						<< 0x19U)) 
				| (0x1ffffffU & (vlTOPp->v__DOT__word_a 
						 >> 7U))) 
			       ^ ((0xffffc000U & (vlTOPp->v__DOT__word_a 
						  << 0xeU)) 
				  | (0x3fffU & (vlTOPp->v__DOT__word_a 
						>> 0x12U)))) 
			      ^ (0x1fffffffU & (vlTOPp->v__DOT__word_a 
						>> 3U)))),32);
	vcdp->chgBus  (c+40,(((((0xffff8000U & (vlTOPp->v__DOT__word_b 
						<< 0xfU)) 
				| (0x7fffU & (vlTOPp->v__DOT__word_b 
					      >> 0x11U))) 
			       ^ ((0xffffe000U & (vlTOPp->v__DOT__word_b 
						  << 0xdU)) 
				  | (0x1fffU & (vlTOPp->v__DOT__word_b 
						>> 0x13U)))) 
			      ^ (0x3fffffU & (vlTOPp->v__DOT__word_b 
					      >> 0xaU)))),32);
    }
}

void Vsha_core::traceChgThis__3(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+41,(((vlTOPp->v__DOT__core_op__DOT__temp 
			       + (((vlTOPp->v__DOT__current_state[7U] 
				    & vlTOPp->v__DOT__current_state[6U]) 
				   ^ (vlTOPp->v__DOT__current_state[7U] 
				      & vlTOPp->v__DOT__current_state[5U])) 
				  ^ (vlTOPp->v__DOT__current_state[6U] 
				     & vlTOPp->v__DOT__current_state[5U]))) 
			      + ((((0xc0000000U & (
						   vlTOPp->v__DOT__current_state[7U] 
						   << 0x1eU)) 
				   | (0x3fffffffU & 
				      (vlTOPp->v__DOT__current_state[7U] 
				       >> 2U))) ^ (
						   (0xfff80000U 
						    & (vlTOPp->v__DOT__current_state[7U] 
						       << 0x13U)) 
						   | (0x7ffffU 
						      & (vlTOPp->v__DOT__current_state[7U] 
							 >> 0xdU)))) 
				 ^ ((0xfffffc00U & 
				     (vlTOPp->v__DOT__current_state[7U] 
				      << 0xaU)) | (0x3ffU 
						   & (vlTOPp->v__DOT__current_state[7U] 
						      >> 0x16U)))))),32);
	vcdp->chgBus  (c+42,((vlTOPp->v__DOT__current_state[4U] 
			      + vlTOPp->v__DOT__core_op__DOT__temp)),32);
    }
}

void Vsha_core::traceChgThis__4(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+43,(vlTOPp->v__DOT__state));
	vcdp->chgArray(c+44,(vlTOPp->v__DOT__current_state),256);
	vcdp->chgBus  (c+53,(vlTOPp->v__DOT__addr_a),6);
	vcdp->chgBus  (c+54,(vlTOPp->v__DOT__addr_b),6);
	vcdp->chgBus  (c+55,(vlTOPp->v__DOT__addr_c),6);
	vcdp->chgBus  (c+56,(vlTOPp->v__DOT__addr_d),6);
	vcdp->chgBus  (c+52,(vlTOPp->v__DOT__round_constant),32);
	vcdp->chgBus  (c+57,(vlTOPp->v__DOT__current_state[7U]),32);
	vcdp->chgBus  (c+58,(vlTOPp->v__DOT__current_state[6U]),32);
	vcdp->chgBus  (c+59,(vlTOPp->v__DOT__current_state[5U]),32);
	vcdp->chgBus  (c+60,(vlTOPp->v__DOT__current_state[4U]),32);
	vcdp->chgBus  (c+61,(vlTOPp->v__DOT__current_state[3U]),32);
	vcdp->chgBus  (c+62,(vlTOPp->v__DOT__current_state[2U]),32);
	vcdp->chgBus  (c+63,(vlTOPp->v__DOT__current_state[1U]),32);
	vcdp->chgBus  (c+64,(vlTOPp->v__DOT__current_state[0U]),32);
	vcdp->chgBus  (c+65,(((vlTOPp->v__DOT__current_state[3U] 
			       & vlTOPp->v__DOT__current_state[2U]) 
			      ^ ((~ vlTOPp->v__DOT__current_state[3U]) 
				 & vlTOPp->v__DOT__current_state[1U]))),32);
	vcdp->chgBus  (c+66,((((vlTOPp->v__DOT__current_state[7U] 
				& vlTOPp->v__DOT__current_state[6U]) 
			       ^ (vlTOPp->v__DOT__current_state[7U] 
				  & vlTOPp->v__DOT__current_state[5U])) 
			      ^ (vlTOPp->v__DOT__current_state[6U] 
				 & vlTOPp->v__DOT__current_state[5U]))),32);
	vcdp->chgBus  (c+67,(((((0xc0000000U & (vlTOPp->v__DOT__current_state[7U] 
						<< 0x1eU)) 
				| (0x3fffffffU & (vlTOPp->v__DOT__current_state[7U] 
						  >> 2U))) 
			       ^ ((0xfff80000U & (vlTOPp->v__DOT__current_state[7U] 
						  << 0x13U)) 
				  | (0x7ffffU & (vlTOPp->v__DOT__current_state[7U] 
						 >> 0xdU)))) 
			      ^ ((0xfffffc00U & (vlTOPp->v__DOT__current_state[7U] 
						 << 0xaU)) 
				 | (0x3ffU & (vlTOPp->v__DOT__current_state[7U] 
					      >> 0x16U))))),32);
	vcdp->chgBus  (c+68,(((((0xfc000000U & (vlTOPp->v__DOT__current_state[3U] 
						<< 0x1aU)) 
				| (0x3ffffffU & ((vlTOPp->v__DOT__current_state[4U] 
						  << 0x1aU) 
						 | (vlTOPp->v__DOT__current_state[3U] 
						    >> 6U)))) 
			       ^ ((0xffe00000U & (vlTOPp->v__DOT__current_state[3U] 
						  << 0x15U)) 
				  | (0x1fffffU & ((
						   vlTOPp->v__DOT__current_state[4U] 
						   << 0x15U) 
						  | (vlTOPp->v__DOT__current_state[3U] 
						     >> 0xbU))))) 
			      ^ ((0xffffff80U & (vlTOPp->v__DOT__current_state[3U] 
						 << 7U)) 
				 | (0x7fU & ((vlTOPp->v__DOT__current_state[4U] 
					      << 7U) 
					     | (vlTOPp->v__DOT__current_state[3U] 
						>> 0x19U)))))),32);
    }
}

void Vsha_core::traceChgThis__5(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+69,(vlTOPp->v__DOT__round),6);
    }
}

void Vsha_core::traceChgThis__6(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+70,(vlTOPp->start_state),256);
	vcdp->chgBit  (c+78,(vlTOPp->start));
	vcdp->chgBit  (c+79,(vlTOPp->clk));
	vcdp->chgArray(c+80,(vlTOPp->input_message),512);
	vcdp->chgBit  (c+96,(vlTOPp->rst));
	vcdp->chgArray(c+97,(vlTOPp->result),256);
	vcdp->chgBit  (c+105,(vlTOPp->done));
    }
}
