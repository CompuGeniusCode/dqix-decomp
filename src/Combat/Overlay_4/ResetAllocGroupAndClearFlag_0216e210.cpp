#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
struct Struct020a9ea4;
void ClearStruct020a9ea4(struct Struct020a9ea4* p);

extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e210  (semantic: ResetAllocGroupAndClearFlag_0216e210)
extern "C" ARM int func_ov004_0216e210(void* a) {
    void* base = func_ov011_021845f8(a, 6);
    if (base != NULL) {
        SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
        *(void**)&data_ov004_02171034[0x10] = alloc->Allocate(8);
    }
    ClearStruct020a9ea4(*(struct Struct020a9ea4**)&data_ov004_02171034[0x10]);
    data_ov004_02171034[5] = 0;
    return 0;
}
