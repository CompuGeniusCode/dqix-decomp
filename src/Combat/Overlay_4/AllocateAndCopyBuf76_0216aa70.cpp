#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Block0x4c_0216aa70 { unsigned int w[0x4c / 4]; };
extern struct Block0x4c_0216aa70 data_ov004_021700ec;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
int Reset3FieldsAndDispatch_0216aa10(void);

// USA: func_ov004_0216aa70
ARM void AllocateAndCopyBuf76_0216aa70(SafeAllocator* a, void* target) {
    struct Block0x4c_0216aa70 tmp = data_ov004_021700ec;
    void* buf = a->Allocate(0x4c);
    memcpy(buf, &tmp, 0x4c);
    func_ov011_02184a24(target, buf, 0x13);
    func_ov011_02184c28(target, (void*)Reset3FieldsAndDispatch_0216aa10);
}
