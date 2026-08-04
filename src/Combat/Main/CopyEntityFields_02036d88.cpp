#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

struct BitField0x40_02036d88 { unsigned char low : 3; unsigned char high : 5; };

// USA: func_02036d88  (semantic: CopyEntityFields_02036d88)
extern "C" ARM void func_02036d88(void* srcObj, void* dstObj) {
    char* src = (char*)srcObj;
    char* dst = (char*)dstObj;
    *(short*)(dst + 0x2) = *(short*)(src + 0x2);
    *(int*)(dst + 0x64) = *(int*)(src + 0x64);
    *(int*)(dst + 0x68) = *(int*)(src + 0x68);
    *(int*)(dst + 0x8) = *(int*)(src + 0x8);
    CopyVec3((int*)(dst + 0x44), (int*)(src + 0x44));
    CopyVec3((int*)(dst + 0x50), (int*)(src + 0x50));
    *(short*)(dst + 0x5c) = *(short*)(src + 0x5c);
    *(short*)(dst + 0x5e) = *(short*)(src + 0x5e);
    *(short*)(dst + 0x60) = *(short*)(src + 0x60);
    ((BitField0x40_02036d88*)(dst + 0x40))->high = ((BitField0x40_02036d88*)(src + 0x40))->high;
    *(unsigned short*)(dst + 0x78) = *(unsigned short*)(src + 0x78);
    *(unsigned short*)(dst + 0x7a) = *(unsigned short*)(src + 0x7a);
    *(int*)(dst + 0xc) = *(int*)(src + 0xc);
}
