#include <globaldefs.h>

// Sets bits in the global state-flag word at data_02114e04. Every decompiled caller reaches the
// word through GetGlobalStateFlags, and the clear and test halves are the two functions
// straight after this one.
// The individual bits are not worked out. func_0202b1f4 sets 0x1000000 once its state has
// finished and HandleBrightnessOrDispatchState02012de8 tests the same bit as an already-done
// guard; 0x80 is held only while func_ov001_02163070 has a request outstanding; 0x400 goes in as
// part of the 0x402 func_020a8ac8 writes and is cleared unconditionally by
// func_ov017_02199e98, before that function decides whether to stop the player at all.
extern "C" ARM void SetGlobalStateFlags(unsigned int* stateFlags, unsigned int mask) {
    *stateFlags |= mask;
}
