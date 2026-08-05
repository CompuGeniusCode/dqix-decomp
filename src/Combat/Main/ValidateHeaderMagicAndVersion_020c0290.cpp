#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void VectorizedInvertedMemcpy(void* src, void* dst, int n);

struct Header020c0290 {
    unsigned short magic;
    unsigned short pad2;
    unsigned short pad4;
    unsigned short f6;
};

struct Obj020c0290 {
    char pad0[0x3c];
    unsigned short f3c;
    char pad3e[0x44 - 0x3e];
    int f44;
    char pad48[0x50 - 0x48];
    char f50[8];
};

// USA: func_020c0290  (semantic: ValidateHeaderMagicAndVersion_020c0290)
#pragma optimize_for_size off
extern "C" ARM int func_020c0290(struct Obj020c0290* obj) {
    if (obj == NULL) return 0;
    if (obj->f3c == 0) return 0;

    struct Header020c0290 buf;
    VectorizedInvertedMemcpy(obj->f50, &buf, 8);
    CleanCacheRange(&buf, 8);

    if (obj->f44 != 0) goto fail;
    if (buf.magic != 0x2348 && *(volatile unsigned short*)&buf.magic != 0xbd8a) goto fail;
    if (buf.f6 == 4) return 1;
fail:
    return 0;
}
