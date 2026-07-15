#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021e61a0(void* obj);
extern "C" void func_02034bc4(void* p);

// USA: func_ov023_021e4f18
ARM void DestroyTenAndOne_021e4f18(void* obj) {
    func_ov023_021e61a0(obj);
    for (int i = 0; i < 10; i++) {
        func_02034bc4((char*)obj + i * 0xac);
        ((SafeAllocator*)((char*)obj + 0x6b8 + i * 0x14))->Destroy();
    }
    ((SafeAllocator*)((char*)obj + 0x780))->Destroy();
}
