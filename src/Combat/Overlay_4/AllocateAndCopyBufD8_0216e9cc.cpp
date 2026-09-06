#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Block0xd8_0216e9cc { unsigned int w[0xd8 / 4]; };
extern struct Block0xd8_0216e9cc data_ov004_0217018c;
extern "C" void func_ov011_02184a24(void*, void*, int);

// USA: func_ov004_0216e9cc  (semantic: AllocateAndCopyBufD8_0216e9cc)
extern "C" ARM void func_ov004_0216e9cc(SafeAllocator* a, void* target) {
    struct Block0xd8_0216e9cc tmp = data_ov004_0217018c;
    void* buf = a->Allocate(0xd8);
    memcpy(buf, &tmp, 0xd8);
    func_ov011_02184a24(target, buf, 0x36);
}
