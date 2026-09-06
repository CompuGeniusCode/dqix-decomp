#include <globaldefs.h>

extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);

// USA: func_02033fec
ARM void SetBits0x40000AndFlag0x2(unsigned char* obj) {
    _ZN8Object3D10EnableFlagEi(obj, 0x40000);
    obj[0xe0] |= 0x2;
}
