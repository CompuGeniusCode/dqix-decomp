#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

void ResetGlobalStateArrays_0215a79c(void);
extern "C" void func_ov001_0215a8dc(void);

struct S02165880 { char pad0[4]; void* p4; void* p8; char pad1[0x1c - 0xc]; void* p1c; void* p20; void* p24; };
extern struct S02165880 data_ov001_02165880;

// USA: func_ov001_0215a850
ARM void func_ov001_0215a850(SafeAllocator* allocator) {
    void* p8 = allocator->Allocate(0x260);
    unsigned int size24 = 0xa28;
    data_ov001_02165880.p8 = p8;
    void* p24 = allocator->Allocate(size24);
    unsigned int size20 = 0x700;
    data_ov001_02165880.p24 = p24;
    void* p20 = allocator->Allocate(size20);
    unsigned int size1c = 0x84c0;
    data_ov001_02165880.p20 = p20;
    void* p1c = allocator->Allocate(size1c);
    unsigned int size4 = 0x200;
    data_ov001_02165880.p1c = p1c;
    void* p4 = allocator->Allocate(size4);
    data_ov001_02165880.p4 = p4;
    memset(p4, 0, 0x200);
    ResetGlobalStateArrays_0215a79c();
    func_ov001_0215a8dc();
}
