#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_02184a24(void* obj, void* v1, int v2);
extern unsigned char data_ov004_02170444;

// USA: func_ov004_021633ac
ARM void AllocateAndCopyStruct60_021633ac(SafeAllocator* a, void* obj) {
    void* buf = a->Allocate(0x60);
    memcpy(buf, &data_ov004_02170444, 0x60);
    func_ov011_02184a24(obj, buf, 0x18);
}
