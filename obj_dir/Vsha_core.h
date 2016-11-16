// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vsha_core_H_
#define _Vsha_core_H_

#include "verilated.h"
#include "Vsha_core__Inlines.h"
class Vsha_core__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vsha_core) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    //char	__VpadToAlign4[4];
    VL_INW(start_state,255,0,8);
    VL_INW(input_message,511,0,16);
    VL_OUTW(result,255,0,8);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__state,0,0);
    VL_SIG8(v__DOT__round,5,0);
    VL_SIG8(v__DOT__addr_a,5,0);
    VL_SIG8(v__DOT__addr_b,5,0);
    VL_SIG8(v__DOT__addr_c,5,0);
    VL_SIG8(v__DOT__addr_d,5,0);
    //char	__VpadToAlign146[6];
    VL_SIGW(v__DOT__current_state,255,0,8);
    VL_SIG(v__DOT__round_constant,31,0);
    //char	__VpadToAlign188[4];
    VL_SIGW(v__DOT__output_state,255,0,8);
    VL_SIG(v__DOT__current_message,31,0);
    VL_SIG(v__DOT__word_a,31,0);
    VL_SIG(v__DOT__word_b,31,0);
    VL_SIG(v__DOT__word_c,31,0);
    VL_SIG(v__DOT__word_d,31,0);
    //char	__VpadToAlign244[4];
    VL_SIGW(v__DOT__combined_result,255,0,8);
    VL_SIG(v__DOT__core_op__DOT__temp,31,0);
    //char	__VpadToAlign284[4];
    VL_SIG(v__DOT__message_state[48],31,0);
    VL_SIG(v__DOT__message_chunk[16],31,0);
    VL_SIG(v__DOT__combined_result_chunk[8],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG(__Vtable1_v__DOT__round_constant[64],31,0);
    VL_SIG8(__Vtableidx1,5,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__rst,0,0);
    //char	__VpadToAlign583[1];
    VL_SIG(v__DOT____Vlvbound1,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign596[4];
    Vsha_core__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vsha_core& operator= (const Vsha_core&);	///< Copying not allowed
    Vsha_core(const Vsha_core&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vsha_core(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsha_core();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vsha_core__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vsha_core__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vsha_core__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(Vsha_core__Syms* __restrict vlSymsp);
    static void	_combo__TOP__10(Vsha_core__Syms* __restrict vlSymsp);
    static void	_combo__TOP__6(Vsha_core__Syms* __restrict vlSymsp);
    static void	_combo__TOP__8(Vsha_core__Syms* __restrict vlSymsp);
    static void	_eval(Vsha_core__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vsha_core__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vsha_core__Syms* __restrict vlSymsp);
    static void	_initial__TOP__4(Vsha_core__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vsha_core__Syms* __restrict vlSymsp);
    static void	_settle__TOP__11(Vsha_core__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(Vsha_core__Syms* __restrict vlSymsp);
    static void	_settle__TOP__7(Vsha_core__Syms* __restrict vlSymsp);
    static void	_settle__TOP__9(Vsha_core__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vsha_core__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
