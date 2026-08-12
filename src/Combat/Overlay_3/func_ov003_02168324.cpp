#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int GetGlobal02109400(void);
extern "C" void func_02094ab0(void);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void* obj);
extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void* obj);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void* obj);
extern "C" void func_0205d048(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int TransferBg1CharData(int arg0, int arg1, unsigned int arg2);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02043124(void* self);
void ReinitController02043204(char* obj);
extern "C" void* func_0200f374(void* dst, int count);

// USA: func_ov003_02168324  (semantic: TeardownControllerAndDestroyAllocators_02168324)
extern "C" ARM void func_ov003_02168324(char* obj) {
    GetGlobal02109400();
    func_02094ab0();

    int* reg = (int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(short*)((char*)reg + 0x50) = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)(obj + 0xcc));

    _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(obj + 0xe4);
    _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(obj + 0xe4);
    _Z19InitEntries0205d2bcP11Obj0205d2bc(obj + 0xe4);
    func_0205d048(obj + 0xe4);

    memset(*(void**)(obj + 0x7c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(obj + 0x7c), 0x20);
    TransferBg1CharData((int)*(void**)(obj + 0x7c), 0, 0x20);

    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02043124(g);
    ReinitController02043204((char*)g);
    *(int*)((char*)g + 0x2d8) = 0;
    *(int*)((char*)g + 0x2dc) = 0;
    *(int*)((char*)g + 0x2e0) = 0;
    *(int*)(obj + 0x4e4) = 0;

    SafeAllocator* arr[6];
    func_0200f374(arr, sizeof(arr));
    arr[0] = (SafeAllocator*)(obj + 0x50);
    arr[1] = (SafeAllocator*)(obj + 0x3c);
    arr[2] = (SafeAllocator*)(obj + 0x28);
    arr[3] = (SafeAllocator*)(obj + 0x14);
    arr[4] = (SafeAllocator*)obj;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}
