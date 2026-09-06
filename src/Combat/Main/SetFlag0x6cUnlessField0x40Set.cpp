#include <globaldefs.h>

struct Bits40_37464;
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(struct Bits40_37464* obj);
extern "C" int _ZN8Object3D10MakeHiddenEv(unsigned char* obj);
extern "C" void func_02076a8c(void* p);

// USA: func_02078660
ARM int SetFlag0x6cUnlessField0x40Set(void* p) {
    int r = _ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)p);
    if (r != 0) return r;
    func_02076a8c(p);
    return _ZN8Object3D10MakeHiddenEv((unsigned char*)p);
}
