#include <globaldefs.h>

struct Mtx43_020c19b8 { unsigned int v[12]; };

// SKIP attempt func_020c19b8: same "no C form" idiom family as
// BuildRotYMatrix43_020c199c.cpp and BuildRotationMatrix43_020c197c.cpp --
// target is a pure register-sourced stmia-burst init (1/2/3/3/3 word groups,
// zero ldm/loads). Plain dst->v[i]= in target order compiles to flat
// individual str's, no stmia merge. NOT a match, no // USA: tag.
THUMB void BuildRotZMatrix43_020c19b8(struct Mtx43_020c19b8* dst, int s, int c) {
    dst->v[0] = c;
    dst->v[1] = s;
    dst->v[2] = 0;
    dst->v[3] = -s;
    dst->v[4] = c;
    dst->v[5] = 0;
    dst->v[6] = 0;
    dst->v[7] = 0;
    dst->v[8] = 0x1000;
    dst->v[9] = 0;
    dst->v[10] = 0;
    dst->v[11] = 0;
}
