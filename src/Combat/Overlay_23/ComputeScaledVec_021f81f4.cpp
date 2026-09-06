#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Vec3_021f81f4 { int x; int y; int z; };

struct Obj021f81f4 {
    char pad[0x100];
    unsigned short field100;
    unsigned short field102;
};

// USA: func_ov023_021f81f4  (semantic: ComputeScaledVec_021f81f4)
extern "C" ARM void func_ov023_021f81f4(struct Vec3_021f81f4* out, struct Obj021f81f4* src) {
    int tmp[3];
    __clear(tmp, 0xc);
    tmp[0] = src->field100 << 0xc;
    tmp[1] = src->field102 << 0xc;
    *(int(*)[3])out = *(int(*)[3])tmp;
}
