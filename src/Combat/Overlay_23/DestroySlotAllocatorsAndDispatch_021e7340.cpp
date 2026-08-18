#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);
int func_020c4ac0(void);
extern "C" void _Z31SetVramFieldAndDispatch020c4658t(int value);
extern "C" void func_020c45b0(int);

// USA: func_ov023_021e7340  (semantic: DestroySlotAllocatorsAndDispatch_021e7340)
extern "C" ARM void func_ov023_021e7340(void* obj) {
    char* o = (char*)obj;
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(o + 0x5e4) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(o + 0x5e4)));
        *(int*)(o + 0x5e4) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;
    ClearFlag0x11IfSet((struct Struct02074bf4*)(o + 0x64));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(o + 0x48) << 8);

    func_020c4ac0();
    func_020c45b0(*(int*)(o + 0x40));
    _Z31SetVramFieldAndDispatch020c4658t(*(int*)(o + 0x44));

    SafeAllocator* arr[3] = { (SafeAllocator*)o, (SafeAllocator*)(o + 0x14), (SafeAllocator*)(o + 0x28) };
    for (int i = 0; i < 3; i++) {
        if (arr[i]->GetSignedAllocator() != 0) {
            arr[i]->Destroy();
        }
    }
}
