#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Block0x98_02165df4 { unsigned int w[0x98 / 4]; };
extern struct Block0x98_02165df4 data_ov004_0216ff00;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_02165be4(void);

// USA: func_ov004_02165df4
ARM void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator* a, void* target) {
    struct Block0x98_02165df4 tmp = data_ov004_0216ff00;
    void* buf = a->Allocate(0x98);
    memcpy(buf, &tmp, 0x98);
    func_ov011_02184a24(target, buf, 0x26);
    func_ov011_02184c28(target, (void*)func_ov004_02165be4);
}
