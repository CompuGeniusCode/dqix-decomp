#include <globaldefs.h>

struct Struct02074bd0;
struct Struct02074bf4;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);

// USA: func_ov023_021dcd18  (semantic: SetCaptureRegField730_021dcd18)
#pragma optimize_for_size off
extern "C" ARM void func_ov023_021dcd18(void* obj) {
    signed char mode = *(signed char*)((char*)obj + 0x77c);
    if (mode == 1) {
        ClearFlag0x11IfSet((struct Struct02074bf4*)((char*)obj + 0x118));
        unsigned int* reg = (unsigned int*)0x4001000;
        *reg = (*reg & ~0x1f00) | (*(unsigned int*)((char*)obj + 0x730) << 8);
    } else {
        ClearFlag0x10IfSet((struct Struct02074bd0*)((char*)obj + 0x118));
        unsigned int* reg = (unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | (*(unsigned int*)((char*)obj + 0x730) << 8);
    }
}
