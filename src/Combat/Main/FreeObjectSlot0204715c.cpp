#include <globaldefs.h>

extern "C" void _ZN8Object3D4DrawEb(void* p, int flag);

// USA: func_0204715c
ARM void FreeObjectSlot0204715c(char* obj) {
    void* p = *(void**)(obj + 0xe8);
    if (p != NULL) {
        _ZN8Object3D4DrawEb(p, 1);
        return;
    }
    if (*(unsigned char*)(obj + 0x1d) != 0) {
        _ZN8Object3D4DrawEb(obj + 0x3c, 1);
    }
}
