// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsha_core.h for the primary calling header

#include "Vsha_core.h"         // For This
#include "Vsha_core__Syms.h"

//--------------------
// STATIC VARIABLES

VL_ST_SIG(Vsha_core::__Vtable1_v__DOT__round_constant[64],31,0);

//--------------------

VL_CTOR_IMP(Vsha_core) {
    Vsha_core__Syms* __restrict vlSymsp = __VlSymsp = new Vsha_core__Syms(this, name());
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    VL_RAND_RESET_W(256,start_state);
    start = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512,input_message);
    rst = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256,result);
    done = VL_RAND_RESET_I(1);
    v__DOT__state = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256,v__DOT__current_state);
    v__DOT__round = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<48; ++__Vi0) {
	    v__DOT__message_state[__Vi0] = VL_RAND_RESET_I(32);
    }}
    v__DOT__round_constant = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(256,v__DOT__output_state);
    v__DOT__current_message = VL_RAND_RESET_I(32);
    v__DOT__word_a = VL_RAND_RESET_I(32);
    v__DOT__word_b = VL_RAND_RESET_I(32);
    v__DOT__word_c = VL_RAND_RESET_I(32);
    v__DOT__word_d = VL_RAND_RESET_I(32);
    v__DOT__addr_a = VL_RAND_RESET_I(6);
    v__DOT__addr_b = VL_RAND_RESET_I(6);
    v__DOT__addr_c = VL_RAND_RESET_I(6);
    v__DOT__addr_d = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT__message_chunk[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    v__DOT__combined_result_chunk[__Vi0] = VL_RAND_RESET_I(32);
    }}
    VL_RAND_RESET_W(256,v__DOT__combined_result);
    v__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    v__DOT__core_op__DOT__temp = VL_RAND_RESET_I(32);
    __Vtableidx1 = VL_RAND_RESET_I(6);
    __Vtable1_v__DOT__round_constant[0] = 0x428a2f98U;
    __Vtable1_v__DOT__round_constant[1] = 0x71374491U;
    __Vtable1_v__DOT__round_constant[2] = 0xb5c0fbcfU;
    __Vtable1_v__DOT__round_constant[3] = 0xe9b5dba5U;
    __Vtable1_v__DOT__round_constant[4] = 0x3956c25bU;
    __Vtable1_v__DOT__round_constant[5] = 0x59f111f1U;
    __Vtable1_v__DOT__round_constant[6] = 0x923f82a4U;
    __Vtable1_v__DOT__round_constant[7] = 0xab1c5ed5U;
    __Vtable1_v__DOT__round_constant[8] = 0xd807aa98U;
    __Vtable1_v__DOT__round_constant[9] = 0x12835b01U;
    __Vtable1_v__DOT__round_constant[10] = 0x243185beU;
    __Vtable1_v__DOT__round_constant[11] = 0x550c7dc3U;
    __Vtable1_v__DOT__round_constant[12] = 0x72be5d74U;
    __Vtable1_v__DOT__round_constant[13] = 0x80deb1feU;
    __Vtable1_v__DOT__round_constant[14] = 0x9bdc06a7U;
    __Vtable1_v__DOT__round_constant[15] = 0xc19bf174U;
    __Vtable1_v__DOT__round_constant[16] = 0xe49b69c1U;
    __Vtable1_v__DOT__round_constant[17] = 0xefbe4786U;
    __Vtable1_v__DOT__round_constant[18] = 0xfc19dc6U;
    __Vtable1_v__DOT__round_constant[19] = 0x240ca1ccU;
    __Vtable1_v__DOT__round_constant[20] = 0x2de92c6fU;
    __Vtable1_v__DOT__round_constant[21] = 0x4a7484aaU;
    __Vtable1_v__DOT__round_constant[22] = 0x5cb0a9dcU;
    __Vtable1_v__DOT__round_constant[23] = 0x76f988daU;
    __Vtable1_v__DOT__round_constant[24] = 0x983e5152U;
    __Vtable1_v__DOT__round_constant[25] = 0xa831c66dU;
    __Vtable1_v__DOT__round_constant[26] = 0xb00327c8U;
    __Vtable1_v__DOT__round_constant[27] = 0xbf597fc7U;
    __Vtable1_v__DOT__round_constant[28] = 0xc6e00bf3U;
    __Vtable1_v__DOT__round_constant[29] = 0xd5a79147U;
    __Vtable1_v__DOT__round_constant[30] = 0x6ca6351U;
    __Vtable1_v__DOT__round_constant[31] = 0x14292967U;
    __Vtable1_v__DOT__round_constant[32] = 0x27b70a85U;
    __Vtable1_v__DOT__round_constant[33] = 0x2e1b2138U;
    __Vtable1_v__DOT__round_constant[34] = 0x4d2c6dfcU;
    __Vtable1_v__DOT__round_constant[35] = 0x53380d13U;
    __Vtable1_v__DOT__round_constant[36] = 0x650a7354U;
    __Vtable1_v__DOT__round_constant[37] = 0x766a0abbU;
    __Vtable1_v__DOT__round_constant[38] = 0x81c2c92eU;
    __Vtable1_v__DOT__round_constant[39] = 0x92722c85U;
    __Vtable1_v__DOT__round_constant[40] = 0xa2bfe8a1U;
    __Vtable1_v__DOT__round_constant[41] = 0xa81a664bU;
    __Vtable1_v__DOT__round_constant[42] = 0xc24b8b70U;
    __Vtable1_v__DOT__round_constant[43] = 0xc76c51a3U;
    __Vtable1_v__DOT__round_constant[44] = 0xd192e819U;
    __Vtable1_v__DOT__round_constant[45] = 0xd6990624U;
    __Vtable1_v__DOT__round_constant[46] = 0xf40e3585U;
    __Vtable1_v__DOT__round_constant[47] = 0x106aa070U;
    __Vtable1_v__DOT__round_constant[48] = 0x19a4c116U;
    __Vtable1_v__DOT__round_constant[49] = 0x1e376c08U;
    __Vtable1_v__DOT__round_constant[50] = 0x2748774cU;
    __Vtable1_v__DOT__round_constant[51] = 0x34b0bcb5U;
    __Vtable1_v__DOT__round_constant[52] = 0x391c0cb3U;
    __Vtable1_v__DOT__round_constant[53] = 0x4ed8aa4aU;
    __Vtable1_v__DOT__round_constant[54] = 0x5b9cca4fU;
    __Vtable1_v__DOT__round_constant[55] = 0x682e6ff3U;
    __Vtable1_v__DOT__round_constant[56] = 0x748f82eeU;
    __Vtable1_v__DOT__round_constant[57] = 0x78a5636fU;
    __Vtable1_v__DOT__round_constant[58] = 0x84c87814U;
    __Vtable1_v__DOT__round_constant[59] = 0x8cc70208U;
    __Vtable1_v__DOT__round_constant[60] = 0x90befffaU;
    __Vtable1_v__DOT__round_constant[61] = 0xa4506cebU;
    __Vtable1_v__DOT__round_constant[62] = 0xbef9a3f7U;
    __Vtable1_v__DOT__round_constant[63] = 0xc67178f2U;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__rst = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vsha_core::__Vconfigure(Vsha_core__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsha_core::~Vsha_core() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsha_core::eval() {
    Vsha_core__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vsha_core::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vsha_core::_eval_initial_loop(Vsha_core__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vsha_core::_combo__TOP__1(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_combo__TOP__1\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__message_chunk[0U] = vlTOPp->input_message[0xfU];
    vlTOPp->v__DOT__message_chunk[1U] = vlTOPp->input_message[0xeU];
    vlTOPp->v__DOT__message_chunk[2U] = vlTOPp->input_message[0xdU];
    vlTOPp->v__DOT__message_chunk[3U] = vlTOPp->input_message[0xcU];
    vlTOPp->v__DOT__message_chunk[4U] = vlTOPp->input_message[0xbU];
    vlTOPp->v__DOT__message_chunk[5U] = vlTOPp->input_message[0xaU];
    vlTOPp->v__DOT__message_chunk[6U] = vlTOPp->input_message[9U];
    vlTOPp->v__DOT__message_chunk[7U] = vlTOPp->input_message[8U];
    vlTOPp->v__DOT__message_chunk[8U] = vlTOPp->input_message[7U];
    vlTOPp->v__DOT__message_chunk[9U] = vlTOPp->input_message[6U];
    vlTOPp->v__DOT__message_chunk[0xaU] = vlTOPp->input_message[5U];
    vlTOPp->v__DOT__message_chunk[0xbU] = vlTOPp->input_message[4U];
    vlTOPp->v__DOT__message_chunk[0xcU] = vlTOPp->input_message[3U];
    vlTOPp->v__DOT__message_chunk[0xdU] = vlTOPp->input_message[2U];
    vlTOPp->v__DOT__message_chunk[0xeU] = vlTOPp->input_message[1U];
    vlTOPp->v__DOT__message_chunk[0xfU] = vlTOPp->input_message[0U];
}

VL_INLINE_OPT void Vsha_core::_sequent__TOP__3(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_sequent__TOP__3\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__state,0,0);
    VL_SIG8(__Vdly__v__DOT__round,5,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__message_state__v0,5,0);
    VL_SIG8(__Vdlyvset__v__DOT__message_state__v0,0,0);
    VL_SIG(__Vdlyvval__v__DOT__message_state__v0,31,0);
    // Body
    __Vdly__v__DOT__state = vlTOPp->v__DOT__state;
    __Vdlyvset__v__DOT__message_state__v0 = 0U;
    __Vdly__v__DOT__round = vlTOPp->v__DOT__round;
    // ALWAYS at sha_core.v:106
    if (vlTOPp->rst) {
	if (vlTOPp->v__DOT__state) {
	    if (vlTOPp->v__DOT__state) {
		if ((0x3fU == (IData)(vlTOPp->v__DOT__round))) {
		    __Vdly__v__DOT__state = 0U;
		} else {
		    __Vdly__v__DOT__round = (0x3fU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__round)));
		    vlTOPp->v__DOT__current_state[0U] 
			= vlTOPp->v__DOT__output_state[0U];
		    vlTOPp->v__DOT__current_state[1U] 
			= vlTOPp->v__DOT__output_state[1U];
		    vlTOPp->v__DOT__current_state[2U] 
			= vlTOPp->v__DOT__output_state[2U];
		    vlTOPp->v__DOT__current_state[3U] 
			= vlTOPp->v__DOT__output_state[3U];
		    vlTOPp->v__DOT__current_state[4U] 
			= vlTOPp->v__DOT__output_state[4U];
		    vlTOPp->v__DOT__current_state[5U] 
			= vlTOPp->v__DOT__output_state[5U];
		    vlTOPp->v__DOT__current_state[6U] 
			= vlTOPp->v__DOT__output_state[6U];
		    vlTOPp->v__DOT__current_state[7U] 
			= vlTOPp->v__DOT__output_state[7U];
		    if ((0x10U <= (IData)(vlTOPp->v__DOT__round))) {
			vlTOPp->v__DOT____Vlvbound1 
			    = vlTOPp->v__DOT__current_message;
			if ((0x2fU >= (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
						- (IData)(0x10U))))) {
			    __Vdlyvval__v__DOT__message_state__v0 
				= vlTOPp->v__DOT____Vlvbound1;
			    __Vdlyvset__v__DOT__message_state__v0 = 1U;
			    __Vdlyvdim0__v__DOT__message_state__v0 
				= (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					    - (IData)(0x10U)));
			}
		    }
		}
	    }
	} else {
	    if (vlTOPp->start) {
		__Vdly__v__DOT__state = 1U;
		vlTOPp->v__DOT__current_state[0U] = 
		    vlTOPp->start_state[0U];
		vlTOPp->v__DOT__current_state[1U] = 
		    vlTOPp->start_state[1U];
		vlTOPp->v__DOT__current_state[2U] = 
		    vlTOPp->start_state[2U];
		vlTOPp->v__DOT__current_state[3U] = 
		    vlTOPp->start_state[3U];
		vlTOPp->v__DOT__current_state[4U] = 
		    vlTOPp->start_state[4U];
		vlTOPp->v__DOT__current_state[5U] = 
		    vlTOPp->start_state[5U];
		vlTOPp->v__DOT__current_state[6U] = 
		    vlTOPp->start_state[6U];
		vlTOPp->v__DOT__current_state[7U] = 
		    vlTOPp->start_state[7U];
		__Vdly__v__DOT__round = 0U;
	    }
	}
    } else {
	__Vdly__v__DOT__state = 0U;
	vlTOPp->v__DOT__current_state[0U] = 0U;
	vlTOPp->v__DOT__current_state[1U] = 0U;
	vlTOPp->v__DOT__current_state[2U] = 0U;
	vlTOPp->v__DOT__current_state[3U] = 0U;
	vlTOPp->v__DOT__current_state[4U] = 0U;
	vlTOPp->v__DOT__current_state[5U] = 0U;
	vlTOPp->v__DOT__current_state[6U] = 0U;
	vlTOPp->v__DOT__current_state[7U] = 0U;
    }
    vlTOPp->v__DOT__state = __Vdly__v__DOT__state;
    // ALWAYSPOST at sha_core.v:132
    if (__Vdlyvset__v__DOT__message_state__v0) {
	vlTOPp->v__DOT__message_state[__Vdlyvdim0__v__DOT__message_state__v0] 
	    = __Vdlyvval__v__DOT__message_state__v0;
    }
    vlTOPp->v__DOT__round = __Vdly__v__DOT__round;
    vlTOPp->done = (1U & ((0x3fU == (IData)(vlTOPp->v__DOT__round))
			   ? 1U : 0U));
    // ALWAYS at k_table.v:32
    vlTOPp->__Vtableidx1 = vlTOPp->v__DOT__round;
    vlTOPp->v__DOT__round_constant = vlTOPp->__Vtable1_v__DOT__round_constant
	[vlTOPp->__Vtableidx1];
    // ALWAYS at message_schedule.v:25
    if ((0x10U > (IData)(vlTOPp->v__DOT__round))) {
	vlTOPp->v__DOT__addr_a = vlTOPp->v__DOT__round;
    } else {
	vlTOPp->v__DOT__addr_a = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(0xfU)));
	vlTOPp->v__DOT__addr_b = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(2U)));
	vlTOPp->v__DOT__addr_c = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(0x10U)));
	vlTOPp->v__DOT__addr_d = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(7U)));
    }
}

void Vsha_core::_initial__TOP__4(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_initial__TOP__4\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at sha_core.v:100
    vlTOPp->v__DOT__state = 0U;
    vlTOPp->v__DOT__current_state[0U] = 0U;
    vlTOPp->v__DOT__current_state[1U] = 0U;
    vlTOPp->v__DOT__current_state[2U] = 0U;
    vlTOPp->v__DOT__current_state[3U] = 0U;
    vlTOPp->v__DOT__current_state[4U] = 0U;
    vlTOPp->v__DOT__current_state[5U] = 0U;
    vlTOPp->v__DOT__current_state[6U] = 0U;
    vlTOPp->v__DOT__current_state[7U] = 0U;
}

void Vsha_core::_settle__TOP__5(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_settle__TOP__5\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->done = (1U & ((0x3fU == (IData)(vlTOPp->v__DOT__round))
			   ? 1U : 0U));
    // ALWAYS at k_table.v:32
    vlTOPp->__Vtableidx1 = vlTOPp->v__DOT__round;
    vlTOPp->v__DOT__round_constant = vlTOPp->__Vtable1_v__DOT__round_constant
	[vlTOPp->__Vtableidx1];
    // ALWAYS at message_schedule.v:25
    if ((0x10U > (IData)(vlTOPp->v__DOT__round))) {
	vlTOPp->v__DOT__addr_a = vlTOPp->v__DOT__round;
    } else {
	vlTOPp->v__DOT__addr_a = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(0xfU)));
	vlTOPp->v__DOT__addr_b = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(2U)));
	vlTOPp->v__DOT__addr_c = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(0x10U)));
	vlTOPp->v__DOT__addr_d = (0x3fU & ((IData)(vlTOPp->v__DOT__round) 
					   - (IData)(7U)));
    }
    vlTOPp->v__DOT__word_a = ((0x10U > (IData)(vlTOPp->v__DOT__addr_a))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_a))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_a) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_a) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_b = ((0x10U > (IData)(vlTOPp->v__DOT__addr_b))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_b))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_b) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_b) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_c = ((0x10U > (IData)(vlTOPp->v__DOT__addr_c))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_c))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_c) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_c) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_d = ((0x10U > (IData)(vlTOPp->v__DOT__addr_d))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_d))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_d) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_d) 
					     - (IData)(0x10U)))]
				   : 0U));
}

VL_INLINE_OPT void Vsha_core::_combo__TOP__6(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_combo__TOP__6\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__word_a = ((0x10U > (IData)(vlTOPp->v__DOT__addr_a))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_a))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_a) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_a) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_b = ((0x10U > (IData)(vlTOPp->v__DOT__addr_b))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_b))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_b) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_b) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_c = ((0x10U > (IData)(vlTOPp->v__DOT__addr_c))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_c))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_c) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_c) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__word_d = ((0x10U > (IData)(vlTOPp->v__DOT__addr_d))
			       ? vlTOPp->v__DOT__message_chunk
			      [(0xfU & (IData)(vlTOPp->v__DOT__addr_d))]
			       : ((0x2fU >= (0x3fU 
					     & ((IData)(vlTOPp->v__DOT__addr_d) 
						- (IData)(0x10U))))
				   ? vlTOPp->v__DOT__message_state
				  [(0x3fU & ((IData)(vlTOPp->v__DOT__addr_d) 
					     - (IData)(0x10U)))]
				   : 0U));
    vlTOPp->v__DOT__current_message = ((0x10U > (IData)(vlTOPp->v__DOT__round))
				        ? vlTOPp->v__DOT__word_a
				        : (((vlTOPp->v__DOT__word_c 
					     + ((((0xfe000000U 
						   & (vlTOPp->v__DOT__word_a 
						      << 0x19U)) 
						  | (0x1ffffffU 
						     & (vlTOPp->v__DOT__word_a 
							>> 7U))) 
						 ^ 
						 ((0xffffc000U 
						   & (vlTOPp->v__DOT__word_a 
						      << 0xeU)) 
						  | (0x3fffU 
						     & (vlTOPp->v__DOT__word_a 
							>> 0x12U)))) 
						^ (0x1fffffffU 
						   & (vlTOPp->v__DOT__word_a 
						      >> 3U)))) 
					    + vlTOPp->v__DOT__word_d) 
					   + ((((0xffff8000U 
						 & (vlTOPp->v__DOT__word_b 
						    << 0xfU)) 
						| (0x7fffU 
						   & (vlTOPp->v__DOT__word_b 
						      >> 0x11U))) 
					       ^ ((0xffffe000U 
						   & (vlTOPp->v__DOT__word_b 
						      << 0xdU)) 
						  | (0x1fffU 
						     & (vlTOPp->v__DOT__word_b 
							>> 0x13U)))) 
					      ^ (0x3fffffU 
						 & (vlTOPp->v__DOT__word_b 
						    >> 0xaU)))));
}

void Vsha_core::_settle__TOP__7(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_settle__TOP__7\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__current_message = ((0x10U > (IData)(vlTOPp->v__DOT__round))
				        ? vlTOPp->v__DOT__word_a
				        : (((vlTOPp->v__DOT__word_c 
					     + ((((0xfe000000U 
						   & (vlTOPp->v__DOT__word_a 
						      << 0x19U)) 
						  | (0x1ffffffU 
						     & (vlTOPp->v__DOT__word_a 
							>> 7U))) 
						 ^ 
						 ((0xffffc000U 
						   & (vlTOPp->v__DOT__word_a 
						      << 0xeU)) 
						  | (0x3fffU 
						     & (vlTOPp->v__DOT__word_a 
							>> 0x12U)))) 
						^ (0x1fffffffU 
						   & (vlTOPp->v__DOT__word_a 
						      >> 3U)))) 
					    + vlTOPp->v__DOT__word_d) 
					   + ((((0xffff8000U 
						 & (vlTOPp->v__DOT__word_b 
						    << 0xfU)) 
						| (0x7fffU 
						   & (vlTOPp->v__DOT__word_b 
						      >> 0x11U))) 
					       ^ ((0xffffe000U 
						   & (vlTOPp->v__DOT__word_b 
						      << 0xdU)) 
						  | (0x1fffU 
						     & (vlTOPp->v__DOT__word_b 
							>> 0x13U)))) 
					      ^ (0x3fffffU 
						 & (vlTOPp->v__DOT__word_b 
						    >> 0xaU)))));
    vlTOPp->v__DOT__core_op__DOT__temp = ((((vlTOPp->v__DOT__current_state[0U] 
					     + vlTOPp->v__DOT__round_constant) 
					    + vlTOPp->v__DOT__current_message) 
					   + ((vlTOPp->v__DOT__current_state[3U] 
					       & vlTOPp->v__DOT__current_state[2U]) 
					      ^ ((~ 
						  vlTOPp->v__DOT__current_state[3U]) 
						 & vlTOPp->v__DOT__current_state[1U]))) 
					  + ((((0xfc000000U 
						& (vlTOPp->v__DOT__current_state[3U] 
						   << 0x1aU)) 
					       | (0x3ffffffU 
						  & ((vlTOPp->v__DOT__current_state[4U] 
						      << 0x1aU) 
						     | (vlTOPp->v__DOT__current_state[3U] 
							>> 6U)))) 
					      ^ ((0xffe00000U 
						  & (vlTOPp->v__DOT__current_state[3U] 
						     << 0x15U)) 
						 | (0x1fffffU 
						    & ((vlTOPp->v__DOT__current_state[4U] 
							<< 0x15U) 
						       | (vlTOPp->v__DOT__current_state[3U] 
							  >> 0xbU))))) 
					     ^ ((0xffffff80U 
						 & (vlTOPp->v__DOT__current_state[3U] 
						    << 7U)) 
						| (0x7fU 
						   & ((vlTOPp->v__DOT__current_state[4U] 
						       << 7U) 
						      | (vlTOPp->v__DOT__current_state[3U] 
							 >> 0x19U))))));
}

VL_INLINE_OPT void Vsha_core::_combo__TOP__8(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_combo__TOP__8\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__core_op__DOT__temp = ((((vlTOPp->v__DOT__current_state[0U] 
					     + vlTOPp->v__DOT__round_constant) 
					    + vlTOPp->v__DOT__current_message) 
					   + ((vlTOPp->v__DOT__current_state[3U] 
					       & vlTOPp->v__DOT__current_state[2U]) 
					      ^ ((~ 
						  vlTOPp->v__DOT__current_state[3U]) 
						 & vlTOPp->v__DOT__current_state[1U]))) 
					  + ((((0xfc000000U 
						& (vlTOPp->v__DOT__current_state[3U] 
						   << 0x1aU)) 
					       | (0x3ffffffU 
						  & ((vlTOPp->v__DOT__current_state[4U] 
						      << 0x1aU) 
						     | (vlTOPp->v__DOT__current_state[3U] 
							>> 6U)))) 
					      ^ ((0xffe00000U 
						  & (vlTOPp->v__DOT__current_state[3U] 
						     << 0x15U)) 
						 | (0x1fffffU 
						    & ((vlTOPp->v__DOT__current_state[4U] 
							<< 0x15U) 
						       | (vlTOPp->v__DOT__current_state[3U] 
							  >> 0xbU))))) 
					     ^ ((0xffffff80U 
						 & (vlTOPp->v__DOT__current_state[3U] 
						    << 7U)) 
						| (0x7fU 
						   & ((vlTOPp->v__DOT__current_state[4U] 
						       << 7U) 
						      | (vlTOPp->v__DOT__current_state[3U] 
							 >> 0x19U))))));
    vlTOPp->v__DOT__output_state[0U] = vlTOPp->v__DOT__current_state[1U];
    vlTOPp->v__DOT__output_state[1U] = vlTOPp->v__DOT__current_state[2U];
    vlTOPp->v__DOT__output_state[2U] = vlTOPp->v__DOT__current_state[3U];
    vlTOPp->v__DOT__output_state[3U] = (vlTOPp->v__DOT__current_state[4U] 
					+ vlTOPp->v__DOT__core_op__DOT__temp);
    vlTOPp->v__DOT__output_state[4U] = vlTOPp->v__DOT__current_state[5U];
    vlTOPp->v__DOT__output_state[5U] = vlTOPp->v__DOT__current_state[6U];
    vlTOPp->v__DOT__output_state[6U] = (IData)((((QData)((IData)(
								 ((vlTOPp->v__DOT__core_op__DOT__temp 
								   + 
								   (((vlTOPp->v__DOT__current_state[7U] 
								      & vlTOPp->v__DOT__current_state[6U]) 
								     ^ 
								     (vlTOPp->v__DOT__current_state[7U] 
								      & vlTOPp->v__DOT__current_state[5U])) 
								    ^ 
								    (vlTOPp->v__DOT__current_state[6U] 
								     & vlTOPp->v__DOT__current_state[5U]))) 
								  + 
								  ((((0xc0000000U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0x1eU)) 
								     | (0x3fffffffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 2U))) 
								    ^ 
								    ((0xfff80000U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0x13U)) 
								     | (0x7ffffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 0xdU)))) 
								   ^ 
								   ((0xfffffc00U 
								     & (vlTOPp->v__DOT__current_state[7U] 
									<< 0xaU)) 
								    | (0x3ffU 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  >> 0x16U))))))) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->v__DOT__current_state[7U]))));
    vlTOPp->v__DOT__output_state[7U] = (IData)(((((QData)((IData)(
								  ((vlTOPp->v__DOT__core_op__DOT__temp 
								    + 
								    (((vlTOPp->v__DOT__current_state[7U] 
								       & vlTOPp->v__DOT__current_state[6U]) 
								      ^ 
								      (vlTOPp->v__DOT__current_state[7U] 
								       & vlTOPp->v__DOT__current_state[5U])) 
								     ^ 
								     (vlTOPp->v__DOT__current_state[6U] 
								      & vlTOPp->v__DOT__current_state[5U]))) 
								   + 
								   ((((0xc0000000U 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  << 0x1eU)) 
								      | (0x3fffffffU 
									 & (vlTOPp->v__DOT__current_state[7U] 
									    >> 2U))) 
								     ^ 
								     ((0xfff80000U 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  << 0x13U)) 
								      | (0x7ffffU 
									 & (vlTOPp->v__DOT__current_state[7U] 
									    >> 0xdU)))) 
								    ^ 
								    ((0xfffffc00U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0xaU)) 
								     | (0x3ffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 0x16U))))))) 
						  << 0x20U) 
						 | (QData)((IData)(
								   vlTOPp->v__DOT__current_state[7U]))) 
						>> 0x20U));
}

void Vsha_core::_settle__TOP__9(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_settle__TOP__9\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__output_state[0U] = vlTOPp->v__DOT__current_state[1U];
    vlTOPp->v__DOT__output_state[1U] = vlTOPp->v__DOT__current_state[2U];
    vlTOPp->v__DOT__output_state[2U] = vlTOPp->v__DOT__current_state[3U];
    vlTOPp->v__DOT__output_state[3U] = (vlTOPp->v__DOT__current_state[4U] 
					+ vlTOPp->v__DOT__core_op__DOT__temp);
    vlTOPp->v__DOT__output_state[4U] = vlTOPp->v__DOT__current_state[5U];
    vlTOPp->v__DOT__output_state[5U] = vlTOPp->v__DOT__current_state[6U];
    vlTOPp->v__DOT__output_state[6U] = (IData)((((QData)((IData)(
								 ((vlTOPp->v__DOT__core_op__DOT__temp 
								   + 
								   (((vlTOPp->v__DOT__current_state[7U] 
								      & vlTOPp->v__DOT__current_state[6U]) 
								     ^ 
								     (vlTOPp->v__DOT__current_state[7U] 
								      & vlTOPp->v__DOT__current_state[5U])) 
								    ^ 
								    (vlTOPp->v__DOT__current_state[6U] 
								     & vlTOPp->v__DOT__current_state[5U]))) 
								  + 
								  ((((0xc0000000U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0x1eU)) 
								     | (0x3fffffffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 2U))) 
								    ^ 
								    ((0xfff80000U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0x13U)) 
								     | (0x7ffffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 0xdU)))) 
								   ^ 
								   ((0xfffffc00U 
								     & (vlTOPp->v__DOT__current_state[7U] 
									<< 0xaU)) 
								    | (0x3ffU 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  >> 0x16U))))))) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->v__DOT__current_state[7U]))));
    vlTOPp->v__DOT__output_state[7U] = (IData)(((((QData)((IData)(
								  ((vlTOPp->v__DOT__core_op__DOT__temp 
								    + 
								    (((vlTOPp->v__DOT__current_state[7U] 
								       & vlTOPp->v__DOT__current_state[6U]) 
								      ^ 
								      (vlTOPp->v__DOT__current_state[7U] 
								       & vlTOPp->v__DOT__current_state[5U])) 
								     ^ 
								     (vlTOPp->v__DOT__current_state[6U] 
								      & vlTOPp->v__DOT__current_state[5U]))) 
								   + 
								   ((((0xc0000000U 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  << 0x1eU)) 
								      | (0x3fffffffU 
									 & (vlTOPp->v__DOT__current_state[7U] 
									    >> 2U))) 
								     ^ 
								     ((0xfff80000U 
								       & (vlTOPp->v__DOT__current_state[7U] 
									  << 0x13U)) 
								      | (0x7ffffU 
									 & (vlTOPp->v__DOT__current_state[7U] 
									    >> 0xdU)))) 
								    ^ 
								    ((0xfffffc00U 
								      & (vlTOPp->v__DOT__current_state[7U] 
									 << 0xaU)) 
								     | (0x3ffU 
									& (vlTOPp->v__DOT__current_state[7U] 
									   >> 0x16U))))))) 
						  << 0x20U) 
						 | (QData)((IData)(
								   vlTOPp->v__DOT__current_state[7U]))) 
						>> 0x20U));
    vlTOPp->v__DOT__combined_result_chunk[0U] = (vlTOPp->v__DOT__output_state[7U] 
						 + 
						 vlTOPp->start_state[7U]);
    vlTOPp->v__DOT__combined_result_chunk[1U] = (vlTOPp->v__DOT__output_state[6U] 
						 + 
						 vlTOPp->start_state[6U]);
    vlTOPp->v__DOT__combined_result_chunk[2U] = (vlTOPp->v__DOT__output_state[5U] 
						 + 
						 vlTOPp->start_state[5U]);
    vlTOPp->v__DOT__combined_result_chunk[3U] = (vlTOPp->v__DOT__output_state[4U] 
						 + 
						 vlTOPp->start_state[4U]);
    vlTOPp->v__DOT__combined_result_chunk[4U] = (vlTOPp->v__DOT__output_state[3U] 
						 + 
						 vlTOPp->start_state[3U]);
    vlTOPp->v__DOT__combined_result_chunk[5U] = (vlTOPp->v__DOT__output_state[2U] 
						 + 
						 vlTOPp->start_state[2U]);
    vlTOPp->v__DOT__combined_result_chunk[6U] = (vlTOPp->v__DOT__output_state[1U] 
						 + 
						 vlTOPp->start_state[1U]);
    vlTOPp->v__DOT__combined_result_chunk[7U] = (vlTOPp->v__DOT__output_state[0U] 
						 + 
						 vlTOPp->start_state[0U]);
}

VL_INLINE_OPT void Vsha_core::_combo__TOP__10(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_combo__TOP__10\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__combined_result_chunk[0U] = (vlTOPp->v__DOT__output_state[7U] 
						 + 
						 vlTOPp->start_state[7U]);
    vlTOPp->v__DOT__combined_result_chunk[1U] = (vlTOPp->v__DOT__output_state[6U] 
						 + 
						 vlTOPp->start_state[6U]);
    vlTOPp->v__DOT__combined_result_chunk[2U] = (vlTOPp->v__DOT__output_state[5U] 
						 + 
						 vlTOPp->start_state[5U]);
    vlTOPp->v__DOT__combined_result_chunk[3U] = (vlTOPp->v__DOT__output_state[4U] 
						 + 
						 vlTOPp->start_state[4U]);
    vlTOPp->v__DOT__combined_result_chunk[4U] = (vlTOPp->v__DOT__output_state[3U] 
						 + 
						 vlTOPp->start_state[3U]);
    vlTOPp->v__DOT__combined_result_chunk[5U] = (vlTOPp->v__DOT__output_state[2U] 
						 + 
						 vlTOPp->start_state[2U]);
    vlTOPp->v__DOT__combined_result_chunk[6U] = (vlTOPp->v__DOT__output_state[1U] 
						 + 
						 vlTOPp->start_state[1U]);
    vlTOPp->v__DOT__combined_result_chunk[7U] = (vlTOPp->v__DOT__output_state[0U] 
						 + 
						 vlTOPp->start_state[0U]);
    vlTOPp->result[0U] = vlTOPp->v__DOT__combined_result_chunk
	[7U];
    vlTOPp->result[1U] = vlTOPp->v__DOT__combined_result_chunk
	[6U];
    vlTOPp->result[2U] = vlTOPp->v__DOT__combined_result_chunk
	[5U];
    vlTOPp->result[3U] = vlTOPp->v__DOT__combined_result_chunk
	[4U];
    vlTOPp->result[4U] = vlTOPp->v__DOT__combined_result_chunk
	[3U];
    vlTOPp->result[5U] = vlTOPp->v__DOT__combined_result_chunk
	[2U];
    vlTOPp->result[6U] = (IData)((((QData)((IData)(
						   vlTOPp->v__DOT__combined_result_chunk
						   [0U])) 
				   << 0x20U) | (QData)((IData)(
							       vlTOPp->v__DOT__combined_result_chunk
							       [1U]))));
    vlTOPp->result[7U] = (IData)(((((QData)((IData)(
						    vlTOPp->v__DOT__combined_result_chunk
						    [0U])) 
				    << 0x20U) | (QData)((IData)(
								vlTOPp->v__DOT__combined_result_chunk
								[1U]))) 
				  >> 0x20U));
}

void Vsha_core::_settle__TOP__11(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_settle__TOP__11\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->result[0U] = vlTOPp->v__DOT__combined_result_chunk
	[7U];
    vlTOPp->result[1U] = vlTOPp->v__DOT__combined_result_chunk
	[6U];
    vlTOPp->result[2U] = vlTOPp->v__DOT__combined_result_chunk
	[5U];
    vlTOPp->result[3U] = vlTOPp->v__DOT__combined_result_chunk
	[4U];
    vlTOPp->result[4U] = vlTOPp->v__DOT__combined_result_chunk
	[3U];
    vlTOPp->result[5U] = vlTOPp->v__DOT__combined_result_chunk
	[2U];
    vlTOPp->result[6U] = (IData)((((QData)((IData)(
						   vlTOPp->v__DOT__combined_result_chunk
						   [0U])) 
				   << 0x20U) | (QData)((IData)(
							       vlTOPp->v__DOT__combined_result_chunk
							       [1U]))));
    vlTOPp->result[7U] = (IData)(((((QData)((IData)(
						    vlTOPp->v__DOT__combined_result_chunk
						    [0U])) 
				    << 0x20U) | (QData)((IData)(
								vlTOPp->v__DOT__combined_result_chunk
								[1U]))) 
				  >> 0x20U));
}

void Vsha_core::_eval(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_eval\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->__Vclklast__TOP__rst)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->_combo__TOP__10(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void Vsha_core::_eval_initial(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_eval_initial\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vsha_core::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::final\n"); );
    // Variables
    Vsha_core__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsha_core::_eval_settle(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_eval_settle\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
    vlTOPp->_settle__TOP__11(vlSymsp);
}

VL_INLINE_OPT QData Vsha_core::_change_request(Vsha_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsha_core::_change_request\n"); );
    Vsha_core* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
