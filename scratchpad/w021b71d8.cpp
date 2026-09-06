#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" unsigned short* func_02012fe4(void);
extern AllocatorUnion data_02114e20;
void EmptyStub02012de4(void);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_ov000_0215ce80(void);
extern "C" void func_ov000_0215fab0(void* a, int b);

// USA: func_ov017_021b71d8
ARM void InitAllocatorAndClearSlots_021b71d8(unsigned char* self) {
    GetBattleStruct();
    unsigned short* p = func_02012fe4();
    EmptyStub02012de4();
    func_020a0cc4(0x1f7dc);
    ((SafeAllocator*)(self + 8))->CreateTypeA(AllocateAligned4(&data_02114e20, 0x1f7dc), 0x1f7dc);
    *(unsigned short*)(self + 0x1c) = *p;
    *(void**)(self + 0x6b0) = ((SafeAllocator*)(self + 8))->Allocate(0x8eb4);
    func_ov000_0215ce80();

    int i;
    for (i = 0; i < self[0x6c3]; i++) {
        unsigned char* row = self + i;
        func_ov000_0215fab0(*(void**)(self + 0x6b0), row[0x6c0]);
    }

    memset(self + 0x6c0, 0, 3);
    self[0x6c3] = 0;
}
