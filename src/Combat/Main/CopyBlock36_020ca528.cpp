#include <globaldefs.h>

struct Block36_020ca528 { unsigned int w[9]; };

// SKIP attempt func_020ca528: same family as func_020ca50c (see
// CopyBlock32_020ca50c.cpp) -- target is a straight-line 9-word copy
// (3x {ldmia r0!,{r2,r3,ip}; stmia r1!,{r2,r3,ip}}, no push, no loop).
// Whole-struct `*dst=*src` instead generates a COUNTED LOOP (push{r4,lr};
// mov r4,r0; mov lr,r1; mov ip,#2; 4-word ldm/stm in a loop; tail 1-word
// copy) -- fundamentally different shape, not just a byte diff. NOT a
// match, no // USA: tag.
ARM void CopyBlock36_020ca528(Block36_020ca528* src, Block36_020ca528* dst) {
    *dst = *src;
}
