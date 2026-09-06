#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
void InitBigStruct0205c790(char* obj);

// USA: func_ov017_021acd7c  (semantic: InitObj_021acd7c)
extern "C" ARM void func_ov017_021acd7c(char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);
    obj[0] = 1;
    ((SafeAllocator*)(obj + 0x8))->ResetAllocatorPointer();
    obj[0x1c] = 0;
    obj[0x1d] = 0;
    obj[0x27c] = 0;
    obj[0x27d] = 0;
    obj[0x27e] = 0;
    obj[0x1e] = 0;
    obj[0x1f] = 0;
    obj[0x280] = 0;
    obj[0x27f] = 0;
    *(short*)(obj + 0x40) = -1;
    obj[0x281] = 0;
    obj[0x282] = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = 0;
    VectorizedMemset(obj + 0x2c, 0, 0x14);
    InitBigStruct0205c790(obj + 0x44);
}
