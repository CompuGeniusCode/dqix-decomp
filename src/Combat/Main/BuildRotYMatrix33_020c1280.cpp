#include <globaldefs.h>

struct Mtx33_020c1280 { unsigned int v[9]; };

// SKIP attempt func_020c1280: instruction order/count matches target exactly (14
// thumb instrs), but target splits the repeated-value stores across TWO scratch
// registers (r2 for c/-s, r3 for 0/0x1000 -- ping-pongs back to r2) while every
// source variation tried here (literal reuse, single shared temp, two named
// locals, interleaved redefinition) collapses to ONE reused register (r2) with
// identical byte size. Scratch-reg selection is a no-op via decl order per
// worker_ov_all.md recipe #15; no FORM change found that reproduces the split.
// NOT a match, no // USA: tag.
THUMB void BuildRotYMatrix33_020c1280(struct Mtx33_020c1280* dst, int s, int c) {
    int a = c;
    int b;
    dst->v[0] = a;
    dst->v[8] = a;
    b = 0;
    dst->v[1] = b;
    dst->v[3] = b;
    a = -s;
    dst->v[5] = b;
    dst->v[7] = b;
    b = 0x1000;
    dst->v[2] = a;
    dst->v[4] = b;
    dst->v[6] = s;
}
