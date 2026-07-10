#include <globaldefs.h>

struct Vec3Block020b3850 { unsigned int v[3]; };
struct FlagRegs020b3850 { unsigned char pad[0xfc]; unsigned int flags; };

extern struct Vec3Block020b3850 data_0210a0f0;
extern struct FlagRegs020b3850 data_0210a010;

// USA: func_020b3850
ARM void StoreVec3AndClearFlags020b3850(struct Vec3Block020b3850* src) {
    if (src == NULL) return;
    data_0210a0f0 = *src;
    data_0210a010.flags &= ~0xa4;
}
