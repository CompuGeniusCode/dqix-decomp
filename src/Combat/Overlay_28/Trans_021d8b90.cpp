#include <globaldefs.h>

extern "C" unsigned int _Z18InitStruct020979c0P11Obj020979c0h(unsigned int, unsigned int);
extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv(unsigned int, unsigned int);
extern "C" unsigned int func_ov028_021d98b8();

// USA: func_ov028_021d8b90  (semantic: Trans_021d8b90)
extern "C" ARM unsigned int func_ov028_021d8b90(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov028_021d98b8();
    r1 = 0x0;
    *(unsigned char*)((char*)r4 + 0x1c) = (unsigned char)r1;
    r0 = r4 + 0x20;
    *(unsigned char*)((char*)r4 + 0x1d) = (unsigned char)r1;
    r0 = (unsigned int)_Z18InitStruct020979c0P11Obj020979c0h(r0, r1);
    r1 = 0x0;
    r0 = r4 + 0x44;
    *(unsigned int*)((char*)r4 + 0x40) = (unsigned int)r1;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv(r0, r1);
    r2 = 0x4000000;
    r0 = *(unsigned int*)((char*)r2 + 0x0);
    r1 = 0x0;
    r0 = r0 & 0x1f00;
    r0 = r0 >> 0x8;
    *(unsigned int*)((char*)r4 + 0x58) = (unsigned int)r0;
    r0 = r2 + 0x1000;
    r2 = *(unsigned int*)((char*)r0 + 0x0);
    r0 = r1 - 0x1;
    r2 = r2 & 0x1f00;
    r2 = r2 >> 0x8;
    *(unsigned int*)((char*)r4 + 0x5c) = (unsigned int)r2;
    *(unsigned int*)((char*)r4 + 0x60) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x64) = (unsigned int)r1;
    *(unsigned short*)((char*)r4 + 0x6c) = (unsigned short)r1;
    *(unsigned int*)((char*)r4 + 0x68) = (unsigned int)r1;
    *(unsigned char*)((char*)r4 + 0x6e) = (unsigned char)r1;
    *(unsigned int*)((char*)r4 + 0x70) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0x74) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x78) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x7c) = (unsigned int)r1;
    *(unsigned char*)((char*)r4 + 0x80) = (unsigned char)r1;
    *(unsigned char*)((char*)r4 + 0x81) = (unsigned char)r1;
    return r0;
}
