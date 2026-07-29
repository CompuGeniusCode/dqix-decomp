#include <globaldefs.h>

struct Blk3_020c1868 { unsigned int v[3]; };

// USA: func_020c1868
ARM void ProbeQuad6(Blk3_020c1868* src, Blk3_020c1868* dst) {
    *dst++ = *src++;
    *dst++ = *src++;
}
