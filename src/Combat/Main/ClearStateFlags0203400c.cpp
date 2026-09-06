#include <globaldefs.h>

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

// USA: func_0203400c
ARM void ClearStateFlags0203400c(unsigned char* obj) {
    _ZN8Object3D11DisableFlagEi(obj, 0x40000);
    obj[0xe0] &= ~0x2;
}
