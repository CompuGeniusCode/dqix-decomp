#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Block02156dc8 { unsigned int v[8]; };

extern Block02156dc8 data_ov004_0216faec;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_02156dc8
ARM int AllocateAndDispatch8_02156dc8(SafeAllocator* alloc, int arg) {
    Block02156dc8 local = data_ov004_0216faec;
    void* buf = alloc->Allocate(0x20);
    memcpy(buf, &local, 0x20);
    return func_ov011_02184a24(arg, buf, 0x8);
}
