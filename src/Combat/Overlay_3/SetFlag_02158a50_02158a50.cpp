// USA: func_ov003_02158a50
#include <globaldefs.h>

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
extern unsigned char data_ov003_0217fe16;

ARM void SetFlag_02158a50_02158a50(unsigned char* obj) {
    _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj + 0x280, &data_ov003_0217fe16, 9);
    _ZN8Object3D11DisableFlagEi(obj + 0x280, 0x40000);
    *(int*)(obj + 0x32c) = 1;
}
