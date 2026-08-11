#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int GetGlobal02109400(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0205d048(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
void TransferBg1CharData(int, int, unsigned int);

// USA: func_ov012_02185af0
extern "C" ARM void func_ov012_02185af0(unsigned char* self) {
    func_02094ab0((struct Obj02094ab0*)GetGlobal02109400());

    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)reg + 0x50) = 0;

    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 8));

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(self + 0xac));
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(self + 0xac));
    InitEntries0205d2bc((struct Obj0205d2bc*)(self + 0xac));
    func_0205d048((void*)(self + 0xac));

    memset(*(void**)(self + 0x137c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(self + 0x137c), 0x20);
    TransferBg1CharData((int)*(void**)(self + 0x137c), 0, 0x20);

    *(int*)(self + 0x1374) = 0;
    *(int*)(self + 0x137c) = 0;

    void* ptrs[5];
    ptrs[0] = self + 0x20;
    ptrs[1] = self + 0x34;
    ptrs[2] = self + 0x48;
    ptrs[3] = self + 0x5c;
    ptrs[4] = self + 0x70;

    for (int i = 0; i < 5; i++) {
        SafeAllocator* p = (SafeAllocator*)ptrs[i];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}
