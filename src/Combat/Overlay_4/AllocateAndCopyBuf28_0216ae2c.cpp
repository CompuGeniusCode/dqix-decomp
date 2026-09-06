#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Block0x1c_0216ae2c { unsigned int w[0x1c / 4]; };
extern struct Block0x1c_0216ae2c data_ov004_02170154;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_0216acf8(void);

// USA: func_ov004_0216ae2c
ARM void AllocateAndCopyBuf28_0216ae2c(SafeAllocator* a, void* target) {
    struct Block0x1c_0216ae2c tmp = data_ov004_02170154;
    void* buf = a->Allocate(0x1c);
    memcpy(buf, &tmp, 0x1c);
    func_ov011_02184a24(target, buf, 7);
    func_ov011_02184c28(target, (void*)func_ov004_0216acf8);
}
