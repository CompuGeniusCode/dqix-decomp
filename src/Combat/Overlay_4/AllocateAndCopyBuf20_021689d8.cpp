#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_02184a24(void* a, void* b, int c);
struct Buf021689d8 { unsigned int w[5]; };
extern struct Buf021689d8 data_ov004_021700c0;

// USA: func_ov004_021689d8
ARM void AllocateAndCopyBuf20_021689d8(SafeAllocator* a, void* target) {
    struct Buf021689d8 buf = data_ov004_021700c0;
    void* allocated = a->Allocate(0x14);
    memcpy(allocated, &buf, 0x14);
    func_ov011_02184a24(target, allocated, 5);
}
