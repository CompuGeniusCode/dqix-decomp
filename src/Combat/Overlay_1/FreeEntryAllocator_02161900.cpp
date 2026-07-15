#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern void* data_ov001_021658b8[];

// USA: func_ov001_02161900
ARM int FreeEntryAllocator_02161900(void* obj) {
    int idx = func_ov017_021d60f4(obj);
    void* entry = data_ov001_021658b8[idx];
    if (entry != NULL) {
        HMRFAllocator* alloc = *(HMRFAllocator**)entry;
        alloc->Free(1);
    }
    return 1;
}
