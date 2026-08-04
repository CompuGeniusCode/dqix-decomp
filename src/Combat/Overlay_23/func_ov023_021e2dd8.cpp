#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void ZeroInit020de848(void* obj);
void ClearFields_021e20c0(void* p);
void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount);

// USA: func_ov023_021e2dd8
extern "C" ARM void func_ov023_021e2dd8(unsigned char* obj) {
    void* p;
    struct BattleStruct* battle;
    signed char buf[4];
    signed char outCount;
    int i;
    int j;

    p = GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0((unsigned int*)p, 0xf);

    *(unsigned int*)(obj + 0x0) = 0;
    *(unsigned int*)(obj + 0x4) = 0;
    *(unsigned int*)(obj + 0xc) = 0;
    *(unsigned int*)(obj + 0x10) = 0;
    *(unsigned int*)(obj + 0x14) = 0;

    ((SafeAllocator*)(obj + 0x2c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x54))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x68))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x7c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x90))->ResetAllocatorPointer();

    ZeroInit020de848(obj + 0xa4);

    *(unsigned short*)(obj + 0xbc) = 0;
    *(unsigned short*)(obj + 0xbe) = 0;
    *(unsigned int*)(obj + 0xc0) = 0;
    *(unsigned int*)(obj + 0xc4) = 0;
    *(unsigned int*)(obj + 0xc8) = 0;
    *(unsigned int*)(obj + 0xcc) = 0;
    *(unsigned int*)(obj + 0xd0) = 0;

    ClearFields_021e20c0(obj + 0xd4);

    *(unsigned int*)(obj + 0x128) = 0;
    *(unsigned int*)(obj + 0x12c) = 0;
    *(unsigned int*)(obj + 0x134) = 0;
    *(unsigned char*)(obj + 0x4e6) = 0;
    *(unsigned char*)(obj + 0x4e7) = 0;
    *(unsigned int*)(obj + 0x120) = 0;
    *(unsigned int*)(obj + 0x124) = 0;
    *(unsigned int*)(obj + 0x4e8) = 0;

    battle = GetBattleStruct();
    outCount = 0;
    for (i = 0; i < 4; i++) buf[i] = -1;
    FilterSlotsWithFlag0x800020dc4d0(buf, &outCount);
    for (j = 0; j < 4; j++) {
        signed char v = buf[j];
        *(int*)((char*)obj + j * 4 + 0x4ec) = v;
        GetCombatantWithFlag0x100(battle, v);
    }

    *(int*)(obj + 0x4e8) = outCount;
    *(unsigned char*)(obj + 0x4e4) = 1;
    *(unsigned int*)(obj + 0x630) = 0;
    memset(obj + 0x634, 0, 2);
    *(unsigned char*)(obj + 0x636) = 0;
    *(unsigned int*)(obj + 0x638) = 0;
    *(unsigned int*)(obj + 0x63c) = 0;
    *(unsigned int*)(obj + 0x640) = 0;
    *(unsigned int*)(obj + 0x644) = 0;
}
