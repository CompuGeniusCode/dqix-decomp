#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_0207de48(void* p, int a, int b);
extern void RestorePairTableFromBuffer(int* out);
extern void WriteGlobalPair020bb92c(int* src);

extern AllocatorUnion data_02114e20;

struct IndexEntry021a0630 { int index; int pad4; };
struct SizeEntry021a0630 { int size; int pad4; };
extern IndexEntry021a0630 data_ov017_021d66c8[];
extern SizeEntry021a0630 data_ov017_021d66cc[];

struct Entry021a0630 { int a; int pad4; int pad8; };
extern Entry021a0630 data_ov017_021d6818[];
extern Entry021a0630 data_ov017_021d6820[];
extern Entry021a0630 data_ov017_021d681c[];

extern Entry021a0630 data_ov017_021d6800[];
extern Entry021a0630 data_ov017_021d6808[];
extern Entry021a0630 data_ov017_021d6804[];

// USA: func_ov017_021a0630
extern "C" ARM void InitAllocatorsAndPairTables_021a0630(char* self) {
    char* alloc = self + 0x38;
    int i = 0;
    for (; data_ov017_021d66cc[i].size != 0; i++) {
        int size = data_ov017_021d66cc[i].size;
        void* buf = AllocateAligned4(&data_02114e20, size);
        int idx = data_ov017_021d66c8[i].index;
        SafeAllocator* a = (SafeAllocator*)(alloc + idx * 0x14);
        a->CreateTypeA(buf, size);
    }

    RestorePairTableFromBuffer((int*)(self + 0x278 + 0x2800));
    WriteGlobalPair020bb92c((int*)(self + 0xad0 + 0x2000));

    int j = 0;
    for (; data_ov017_021d681c[j].a != 0; j++) {
        void* p = (self + 0x2cc) + data_ov017_021d6818[j].a * 0x70;
        func_0207de48(p, data_ov017_021d681c[j].a, data_ov017_021d6820[j].a);
    }

    RestorePairTableFromBuffer((int*)(self + 0x2a8 + 0x2800));

    int k = 0;
    for (; data_ov017_021d6804[k].a != 0; k++) {
        void* p = (self + 0x2cc) + data_ov017_021d6800[k].a * 0x70;
        func_0207de48(p, data_ov017_021d6804[k].a, data_ov017_021d6808[k].a);
    }

    func_0207de48(self + 0x29c + 0xc00, 0x8000, 0x400);
    func_0207de48(self + 0x30c + 0xc00, 0x4000, 0x400);
}
