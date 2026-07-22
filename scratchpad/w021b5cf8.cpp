#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0218d510(int a, void* b);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
int GetField0x3acValue(struct BattleStruct* battleStruct);
struct Holder020159c0;
void ClearMatchingEntries020159c0(struct Holder020159c0* holder, int key);
int GetData02104304Field4(void);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern char data_ov017_021d7bf8[];

// USA: func_ov017_021b5cf8
ARM int InitAllocatorOrClearEntries_021b5cf8(char* self) {
    if (*(unsigned short*)(self + 0x12) == 0x5617) {
        self[0x54] = 1;
        ((SafeAllocator*)(self + 0x58))->ResetAllocatorPointer();
        ((SafeAllocator*)(self + 0x58))->CreateTypeA(AllocateAligned4(&data_02114e20, 0x4000), 0x4000);
        ((SafeAllocator*)(self + 0x58))->Reset();
        func_ov017_0218d510(func_ov017_0218b5b0(), self + 0x58);
    } else {
        struct BattleStruct* battle = GetBattleStruct();
        void* holder = func_02012fe4();
        ClearMatchingEntries020159c0((struct Holder020159c0*)holder, (signed char)GetField0x3acValue(battle));
        char buf[0x80];
        sprintf(buf, data_ov017_021d7bf8, *(signed char*)(self + 0x17), *(signed short*)(self + 0x14));
        *(int*)(self + 0x28) = CallFunc0202fa38ZeroPad(GetData02104304Field4(), (int)buf, 0);
    }
    return 3;
}
