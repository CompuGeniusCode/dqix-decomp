#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void EmptyDestructor0205a494(void* obj);

// USA: func_ov003_0216d77c  (semantic: DestroyOverlayAllocatorsAndSetDispcnt_0216d77c)
extern "C" ARM void func_ov003_0216d77c(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    if (((SafeAllocator*)(o + 0x12fc))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0x12fc))->Destroy();
    }
    if (((SafeAllocator*)(o + 0x1310))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0x1310))->Destroy();
    }
    EmptyDestructor0205a494(o + 0x126c);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
