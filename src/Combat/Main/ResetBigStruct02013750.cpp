#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void _ZN12ZoneFeatures5ResetEv(void* obj);
void ZeroInit020de848(void* obj);
struct Struct0207a5b8;
void InitDefaultState0207a5b8(struct Struct0207a5b8* s);
void ResetFourSubStructs(char* base);

struct AllocAt0x54_02013750 {
    char pad[0x54];
    SafeAllocator alloc;
};

struct AllocAt0x2730_02013750 {
    char pad[0x730 + 0x2000];
    SafeAllocator alloc;
};

#pragma optimize_for_size off

// USA: func_02013750
ARM void ResetBigStruct02013750(void* obj, int flag) {
    *(int*)((char*)obj + 0x838) = 0;
    *(int*)((char*)obj + 0x83c) = 0;
    *(int*)((char*)obj + 0x424) = 0;
    *(int*)((char*)obj + 0x41c) = 0;
    *(int*)((char*)obj + 0x418) = 0;
    *(unsigned char*)((char*)obj + 0x476) = 0;
    *(unsigned char*)((char*)obj + 0x477) = 0;
    *(int*)((char*)obj + 0x82c) = 0;
    *(unsigned short*)((char*)obj + 0x474) = 0;
    *(int*)((char*)obj + 0x82c) = 0;
    *(unsigned char*)((char*)obj + 0x42c) = 0;
    *(int*)((char*)obj + 0x430) = -1;
    *(int*)((char*)obj + 0x434) = -1;
    *(int*)((char*)obj + 0x438) = -1;
    *(int*)((char*)obj + 0x43c) = -1;
    *(int*)((char*)obj + 0x440) = -1;
    *(int*)((char*)obj + 0x478) = 0;
    *(int*)((char*)obj + 0x47c) = 0;
    *(unsigned char*)((char*)obj + 0x2000 + 0x3bc) = 0;
    *(unsigned char*)((char*)obj + 0x2000 + 0x3bd) = 0;
    *(unsigned char*)((char*)obj + 0x834) = 0;
    _ZN12ZoneFeatures5ResetEv((char*)obj + 0x6c);
    ZeroInit020de848((char*)obj + 0x354 + 0x2400);
    InitDefaultState0207a5b8((struct Struct0207a5b8*)((char*)obj + 0xf4));
    ResetFourSubStructs((char*)obj + 0x600);
    if (!flag) {
        return;
    }
    AllocAt0x2730_02013750* b = (AllocAt0x2730_02013750*)obj;
    if (b->alloc.GetSignedAllocator() != NULL) {
        b->alloc.Destroy();
        b->alloc.ResetAllocatorPointer();
    }
    AllocAt0x54_02013750* a = (AllocAt0x54_02013750*)obj;
    if (a->alloc.GetSignedAllocator() == NULL) {
        return;
    }
    a->alloc.Destroy();
    a->alloc.ResetAllocatorPointer();
}
