#include <globaldefs.h>

struct Block32_020ca50c { unsigned int w[8]; };

// SKIP attempt func_020ca50c: target is a straight-line 8-word block copy that
// keeps r0/r1 as the live src/dst pointers and only borrows r2,r3,ip for 3+3+2
// word chunks (no push, no loop). Whole-struct `*dst=*src` instead routes
// through mwcc's generic block-copy codegen (push{r3,lr}, moves r0/r1 aside
// into lr/ip, uses 4+4 word chunks -- SIZE/OVERGEN). Per-group sub-struct
// assignment (dst->g0=src->g0 etc.) triggers out-of-line helper calls (3x
// bigger). Plain scalar element-wise copy doesn't batch into ldm/stm at all
// (8x separate ldr/str, no merging). No C form found that reproduces the
// direct in-place 3-register-chunk shape. NOT a match, no // USA: tag.
ARM void CopyBlock32_020ca50c(Block32_020ca50c* src, Block32_020ca50c* dst) {
    dst->w[0] = src->w[0];
    dst->w[1] = src->w[1];
    dst->w[2] = src->w[2];
    dst->w[3] = src->w[3];
    dst->w[4] = src->w[4];
    dst->w[5] = src->w[5];
    dst->w[6] = src->w[6];
    dst->w[7] = src->w[7];
}
