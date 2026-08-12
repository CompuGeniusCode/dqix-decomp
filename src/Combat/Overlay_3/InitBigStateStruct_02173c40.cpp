#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"

struct S_a64bc;
void InitFieldsWithDefaults(S_a64bc* p);
void InitStruct0205a444(char* obj);
struct List020727d8;
void ResetListHeader020727d8(List020727d8* list);
struct Obj0217bcb8;
void InitObj0217bcb8(Obj0217bcb8* self);

// USA: func_ov003_02173c40  (semantic: InitBigStateStruct_02173c40)
extern "C" ARM void func_ov003_02173c40(char* obj) {
    obj[0] = 0;
    obj[1] = 0;
    *(short*)(obj + 2) = -1;
    VectorizedMemset(obj + 4, 0, 0x40);
    VectorizedMemset(obj + 0x44, 0, 0x80);

    obj[0xc4] = 0;
    obj[0xca] = 0;
    obj[0xcb] = 0;
    obj[0xcc] = 0;
    *(short*)(obj + 0xc6) = 0;
    *(short*)(obj + 0xc8) = 0;
    *(int*)(obj + 0xd0) = 0;
    obj[0xd4] = 0;
    obj[0xd5] = 0;
    InitFieldsWithDefaults((S_a64bc*)(obj + 0xd8));

    obj[0xec] = 0;
    obj[0xed] = 0;
    obj[0xee] = 0;
    obj[0xef] = 0;
    *(int*)(obj + 0xf0) = -1;
    *(int*)(obj + 0xf4) = -1;
    obj[0x10a] = 0;
    obj[0x10b] = 0;
    obj[0x11c] = 0;
    obj[0x11d] = 0;
    *(int*)(obj + 0x120) = 0;
    *(int*)(obj + 0x124) = 0;
    *(int*)(obj + 0x128) = 0;
    *(int*)(obj + 0x12c) = 0;
    InitStruct0205a444(obj + 0x130);

    ((SafeAllocator*)(obj + 0x184))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x198))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x1ac))->ResetAllocatorPointer();

    *(int*)(obj + 0x1c0) = 0;
    *(int*)(obj + 0x1c4) = 0;
    ResetListHeader020727d8((List020727d8*)(obj + 0x1c8));
    ResetListHeader020727d8((List020727d8*)(obj + 0x1d0));
    ResetListHeader020727d8((List020727d8*)(obj + 0x1d8));

    InitObj0217bcb8((Obj0217bcb8*)(obj + 0x1e0));

    obj[0x344] = 0;
}
