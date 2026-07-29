#include <globaldefs.h>

struct Blk3_020c1868 { unsigned int v[3]; };
struct Blk4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void ProbeLoop7(Blk3_020c1868* src, Blk4_020c1868* dst) {
    for (int i = 0; i < 4; i++) {
        *(Blk3_020c1868*)dst = *src;
        dst->v[3] = 0;
        src++; dst++;
    }
}
