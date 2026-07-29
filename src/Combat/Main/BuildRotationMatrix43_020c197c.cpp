#include <globaldefs.h>

struct FixedMtx43_020c197c { unsigned int v[12]; };

// SKIP attempt func_020c197c: target is a mixed direct-store/stmia-burst matrix-init
// idiom (str v5,v7 direct, then stmia r0!,{..} bursts of 1/2 regs with pointer
// writeback + a mid-sequence "add r0,#0xc" skip). Plain field assignment, pointer
// post-increment, and 64-bit paired stores all get constant-folded by mwcc into
// flat offset str's (no stmia at all) -- same "no C form" idiom family as
// InitStruct020c21dc.cpp (needed hand asm) and ZeroStruct_020ca7d0.cpp (SKIP).
// NOT a match, no // USA: tag.
THUMB void BuildRotationMatrix43_020c197c(struct FixedMtx43_020c197c* m, int s, int c) {
    m->v[5] = s;
    m->v[7] = -s;
    unsigned int* p = m->v;
    *p++ = 1 << 0xc;
    *(unsigned long long*)p = 0;
    p += 2;
    *(unsigned long long*)p = ((unsigned long long)(unsigned int)c << 32) | 0u;
    p += 2;
    p[1] = 0;
    p += 3;
    *(unsigned long long*)p = ((unsigned long long)0u << 32) | (unsigned int)c;
    p += 2;
    *(unsigned long long*)p = 0;
}
