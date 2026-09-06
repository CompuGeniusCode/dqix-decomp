#include <globaldefs.h>

extern "C" void _ZN8Object3D10InitializeEv(void* obj);

// USA: func_020484d0
ARM void SetFlag0x400Reset020484d0(void* obj) {
    _ZN8Object3D10InitializeEv(obj);
    *(unsigned short*)obj |= 0x400;
    *(int*)((char*)obj + 0xb0) = 0;
    *(int*)((char*)obj + 0xac) = 0;
}
