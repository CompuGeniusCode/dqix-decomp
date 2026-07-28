#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_0205d048(void* obj);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);
struct ClearTarget0205a244;
void ClearField0And40205a244(struct ClearTarget0205a244* target);
void EmptyDestructor0205a494(void* obj);
struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40* p);

// USA: func_ov003_0217db88  (semantic: ResetOverlayStateAndSetDispcnt_0217db88)
extern "C" ARM void func_ov003_0217db88(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    func_0205d048(*(void**)(o + 0x90));

    int i;
    for (i = 0; i < 2; i++) {
        ResetRecordList0204afb4((struct List0204afb4*)(*(char**)(o + 0x94) + i * 0x20));
    }

    int j;
    for (j = 0; j < 1; j++) {
        ResetObject0204c754((struct Obj0204c754*)(*(char**)(o + 0x98) + j * 0xe0));
    }

    ClearField0And40205a244((struct ClearTarget0205a244*)(*(void**)(o + 0x38)));

    if (((SafeAllocator*)(o + 0xa4))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0xa4))->Destroy();
    }
    if (((SafeAllocator*)(o + 0xb8))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0xb8))->Destroy();
    }
    EmptyDestructor0205a494(o + 0x3c);
    ResetAndDetach020dfc6c((struct Struct020dfc40*)(o + 0xcc));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
