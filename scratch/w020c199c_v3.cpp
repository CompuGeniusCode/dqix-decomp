#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };

// USA: func_020c199c
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    struct Mtx43_020c199c local;
    local.v[6] = s;
    local.v[0] = c;
    local.v[1] = 0;
    local.v[2] = -s;
    local.v[3] = 0;
    local.v[4] = 0x1000;
    local.v[5] = 0;
    local.v[7] = 0;
    local.v[8] = c;
    local.v[9] = 0;
    local.v[10] = 0;
    local.v[11] = 0;
    *dst = local;
}
