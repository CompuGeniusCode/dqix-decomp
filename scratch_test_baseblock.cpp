#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov004_0215c448(void*);
extern "C" void* func_ov004_0215c474(void*);
extern "C" int InitObjWithMisc_021f6f20(void*, int, int, int, int, unsigned int);

extern "C" int fbb(void* obj) {
    void* base = func_ov011_021845f8(obj, 6);
    if (!base) return 0;
    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)base + 4))->Allocate(0xac);
    if (!block) return 0;
    char localbuf[0xac];
    func_ov004_0215c448(localbuf);
    memcpy(block, localbuf, 0xac);
    if (!InitObjWithMisc_021f6f20(block, (int)obj, 0x6a4, 6, 0, 0)) {
        int result = 0;
        func_ov004_0215c474(localbuf);
        return result;
    }
    int result = 0;
    func_ov004_0215c474(localbuf);
    return result;
}
