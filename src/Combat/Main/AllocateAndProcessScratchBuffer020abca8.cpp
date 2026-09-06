#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Combat/Main/BattleList.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);

// USA: func_020abca8
ARM int AllocateAndProcessScratchBuffer020abca8() {
    BattleStruct* bs = GetBattleStruct();
    int zero = 0;
    *(unsigned char*)((char*)bs + 0x5cc8) = zero;

    void* alloc = AllocateAligned4(&data_02114e20, 0x6fe4);
    if (alloc != NULL) {
        zero = func_02075910(0x10, alloc, 0x6fe4, zero);
        if (zero != 0) {
            func_02075acc(0x8010, alloc, 0x6fe4, 0);
        }
        TailForward02012da4(&data_02114e20, alloc);
    }
    return zero;
}
