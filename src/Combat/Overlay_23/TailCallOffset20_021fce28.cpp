#include <globaldefs.h>

extern "C" int _ZN8Object3D10InitializeEv(void *obj, int a1, int a2, int a3);

// USA: func_ov023_021fce28
ARM int TailCallOffset20_021fce28(void *obj, int a1, int a2, int a3) {
    return _ZN8Object3D10InitializeEv((char*)obj + 0x20, a1, a2, a3);
}
