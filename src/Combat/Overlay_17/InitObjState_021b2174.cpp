#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

extern int data_ov017_021d83f0[2];

// USA: func_ov017_021b2174
ARM void InitObjState_021b2174(unsigned char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);
    obj[0x0] = 0x2d;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = -1;
    data_ov017_021d83f0[1] = 0;
    ((SafeAllocator*)(obj + 0x10))->ResetAllocatorPointer();

    struct Flags38 {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
    };
    Flags38* flags = (Flags38*)(obj + 0x38);
    flags->bit0 = 0;
    flags->bit1 = 0;
    flags->bit2 = 0;
    obj[0x24] = 0;
    *(int*)(obj + 0x30) = 0;
    flags->bit3 = 1;
    flags->bit4 = 0;
    flags->bit5 = 0;

    obj[0x3c] = 0xff;
    obj[0x3d] = 0xff;
    obj[0x3e] = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    obj[0x48] = 0;
}
