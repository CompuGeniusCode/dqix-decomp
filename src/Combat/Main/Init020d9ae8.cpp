#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct020dfc40;
extern void ResetStruct020dfc40(Struct020dfc40* p);

struct Struct020d9ae8 {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned char byte8;
    unsigned char byte9;
    unsigned char pad2[2];
    int field_c;
};

// USA: func_020d9ae8
ARM void Init020d9ae8(Struct020d9ae8* p, int arg1) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x4a;
    p->byte8 = arg1;
    p->byte9 = 0;
    p->field_c = -1;
    memset((char*)p + 0x10, 0, 0x30);
    ResetStruct020dfc40((Struct020dfc40*)((char*)p + 0x40));
    ((SafeAllocator*)((char*)p + 0x58))->ResetAllocatorPointer();
}
