#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_0207de48(void* p, int a, int b);
void RestorePairTableFromBuffer(int* out);
void WriteGlobalPair020bb92c(int* src);
extern "C" int func_020bb588(unsigned int size, int a, int b);

extern AllocatorUnion data_02114e20;

struct Entry8_021a09c8 { int a; int pad4; };
struct Entry0xc_021a09c8 { int a; int pad4; int pad8; };
extern Entry8_021a09c8 data_ov017_021d689c[];
extern Entry8_021a09c8 data_ov017_021d68a0[];
extern Entry0xc_021a09c8 data_ov017_021d6758[];
extern Entry0xc_021a09c8 data_ov017_021d6760[];
extern Entry0xc_021a09c8 data_ov017_021d675c[];
extern Entry0xc_021a09c8 data_ov017_021d6850[];
extern Entry0xc_021a09c8 data_ov017_021d6858[];
extern Entry0xc_021a09c8 data_ov017_021d6854[];

struct Block40_021a09c8 { unsigned int w[10]; };
struct Block8_021a09c8 { unsigned int w[2]; };

// USA: func_ov017_021a09c8  (semantic: InitAllocatorsAndTables_021a09c8)
extern "C" ARM void func_ov017_021a09c8(char* self) {
    int size;
    for (int i = 0; (size = data_ov017_021d68a0[i].a) != 0; i++) {
        void* buf = AllocateAligned4(&data_02114e20, size);
        int idx = data_ov017_021d689c[i].a;
        ((SafeAllocator*)((self + 0x38) + idx * 0x14))->CreateTypeA(buf, size);
    }

    RestorePairTableFromBuffer((int*)(self + 0x2a78));
    WriteGlobalPair020bb92c((int*)(self + 0x2ad0));
    func_020bb588(0x20000, 0, 0);

    {
        int n;
        for (int i = 0; (n = data_ov017_021d675c[i].a) != 0; i++) {
            func_0207de48((self + 0x2cc) + data_ov017_021d6758[i].a * 0x70, n, data_ov017_021d6760[i].a);
        }
    }

    RestorePairTableFromBuffer((int*)(self + 0x2aa8));

    {
        int n;
        for (int i = 0; (n = data_ov017_021d6854[i].a) != 0; i++) {
            func_0207de48((self + 0x2cc) + data_ov017_021d6850[i].a * 0x70, n, data_ov017_021d6858[i].a);
        }
    }

    *(Block40_021a09c8*)(self + 0xf0c) = *(Block40_021a09c8*)(self + 0xbfc);
    *(Block40_021a09c8*)(self + 0xf34) = *(Block40_021a09c8*)(self + 0xc24);

    *(int*)(self + 0xf5c) = *(int*)(self + 0xc4c);
    *(int*)(self + 0xf60) = *(int*)(self + 0xc50);
    *(Block8_021a09c8*)(self + 0xf64) = *(Block8_021a09c8*)(self + 0xc54);
    *(Block8_021a09c8*)(self + 0xf6c) = *(Block8_021a09c8*)(self + 0xc5c);
    *(int*)(self + 0xf74) = *(int*)(self + 0xc64);
    *(int*)(self + 0xf78) = *(int*)(self + 0xc68);
}
