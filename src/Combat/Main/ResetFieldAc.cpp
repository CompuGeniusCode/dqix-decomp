#include <globaldefs.h>

extern "C" void _ZN8Object3D10InitializeEv(void*);

// USA: func_02072ac4
ARM void ResetFieldAc(void* obj) {
    _ZN8Object3D10InitializeEv(obj);
    *(int*)((char*)obj + 0xac) = -1;
}
