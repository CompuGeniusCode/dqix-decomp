#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };

// SKIP attempt func_020c199c: target is a pure register-sourced stmia-burst
// init (v6 store, then stmia bursts of 2/2/2/3/2 words, ZERO ldm/loads at
// all -- every value is already in a register from computation). Every C
// form tried (direct dst->v[i]= in target order, pointer-increment *p++=,
// per-chunk local struct assign via pointer cast, one big local struct then
// *dst=local) either emits flat individual str's (no merge) or a completely
// different shape (stack-materialize + memcpy loop for the big-local case).
// Same "no C form" idiom family as InitStruct020c21dc.cpp (needed hand asm),
// ZeroStruct_020ca7d0.cpp, and BuildRotationMatrix43_020c197c.cpp (see that
// file for the sibling case). NOT a match, no // USA: tag.
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    dst->v[6] = s;
    dst->v[0] = c;
    dst->v[1] = 0;
    dst->v[2] = -s;
    dst->v[3] = 0;
    dst->v[4] = 0x1000;
    dst->v[5] = 0;
    dst->v[7] = 0;
    dst->v[8] = c;
    dst->v[9] = 0;
    dst->v[10] = 0;
    dst->v[11] = 0;
}
