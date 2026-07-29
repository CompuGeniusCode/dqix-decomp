#include <globaldefs.h>

// SKIP attempt func_020c976c: target is "subs r0,r0,#4; bhs self; bx lr" (single fused
// decrement+test instruction, self-branch, unconditional first iteration, HS/carry-flag
// condition). Closest found: "do{count-=4;}while((int)count>=0);" fuses to a single subs
// but picks BPL (N flag) not BHS (C flag) -- same size/shape, wrong condition-code nibble.
// No source form found that makes mwcc reuse the carry flag for a non-zero-constant
// comparison; mwcc does not perform cmp+sub fusion for "if(a>=k) a-=k;"-shaped code either
// (verified empirically). NOT a match, no // USA: tag.
ARM void DelayLoop_020c976c(unsigned int count) {
    do {
        count -= 4;
    } while (count >= 4);
}
