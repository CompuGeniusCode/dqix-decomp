#include <globaldefs.h>

struct Vec3Block020b3880 { unsigned int v[3]; };
struct FlagRegs020b3880 { unsigned char pad[0xfc]; unsigned int flags; };

extern struct Vec3Block020b3880 data_0210a0fc;
extern struct FlagRegs020b3880 data_0210a010;

// USA: func_020b3880
ARM void StoreVec3AndClearFlags020b3880(struct Vec3Block020b3880* src) {
    if (src == NULL) return;
    data_0210a0fc = *src;
    data_0210a010.flags &= ~0xa4;
}
