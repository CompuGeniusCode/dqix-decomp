#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c { signed char byte0, byte1, byte2, byte3; };
void ResetByteHeader(ByteHeader0204693c* p);

// USA: func_ov017_021c2b28
ARM void InitObj021c2b28(void* objRaw, unsigned char a, unsigned char b) {
    unsigned char* obj = (unsigned char*)objRaw;
    ResetByteHeader((ByteHeader0204693c*)obj);
    obj[0] = 0x46;
    ((SafeAllocator*)(obj + 8))->ResetAllocatorPointer();
    obj[0x8c] = 0;
    obj[0x8d] = 0;
    *(int*)(obj + 0x90) = 0;
    obj[0x96] = 0;
    obj[0x94] = a;
    obj[0x95] = b;
}
