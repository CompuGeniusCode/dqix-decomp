#include <globaldefs.h>

struct Dst020b9a2c { unsigned int flags; unsigned int a; unsigned int b; unsigned int c; };
struct Src020b9a2c { unsigned int x; unsigned int y; unsigned int z; };

#pragma optimize_for_size off

// USA: func_020b9a2c
ARM void InitTransformOrCopy020b9a2c(struct Dst020b9a2c* dst, struct Src020b9a2c* src, int unused, unsigned int flag) {
    if (flag & 4) {
        dst->flags |= 1;
    } else {
        dst->a = src->x;
        dst->b = src->y;
        dst->c = src->z;
    }
    dst->flags |= 0x18;
}
