#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void PushInputLogB(int id);
extern "C" char* func_ov017_0218b5b0(void);
extern SafeAllocator* data_ov001_021658b8[1];
extern "C" void func_ov028_021d8b90(void* obj);
extern "C" void func_ov028_021d8b44(void* obj, SafeAllocator* allocator);

// USA: func_ov001_021619bc  (semantic: AllocateAndInitNode_021619bc)
extern "C" ARM int func_ov001_021619bc(void) {
    PushInputLogB(5);
    char* p = *(char**)(func_ov017_0218b5b0() + 0x3000 + 0x734);
    void* newObj = data_ov001_021658b8[0]->Allocate(0x84);
    if (newObj == 0) return 0;
    *(void**)(p + 0x160) = newObj;
    *(unsigned char*)(p + 0x164) = 0;
    func_ov028_021d8b90(newObj);
    func_ov028_021d8b44(newObj, data_ov001_021658b8[0]);
    return 1;
}
