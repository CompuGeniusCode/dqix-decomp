#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern char data_ov004_02170360[0x38];

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_021560b0
ARM int AllocateAndDispatch14_021560b0(SafeAllocator* alloc, int arg) {
    void* buf = alloc->Allocate(0x38);
    memcpy(buf, data_ov004_02170360, 0x38);
    return func_ov011_02184a24(arg, buf, 0xe);
}
