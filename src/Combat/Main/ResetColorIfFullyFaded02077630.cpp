#include <globaldefs.h>

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char lo3 : 3;
    unsigned char hi5 : 5;
};
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(struct Bits40_37464* obj);

extern "C" void _ZN8Vector3iaSERKS_(int* a, int* b);

struct Struct020372b8 {
    char pad[0x40];
    unsigned char lo3 : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short f70;
};
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);

void TrySetMode02076ccc(void*, int);

// USA: func_02077630
ARM void ResetColorIfFullyFaded02077630(void* obj) {
    if (_ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) != 0 && _ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) != 0x1f) {
        return;
    }
    if (_ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) == 0) {
        _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x44), (int*)((char*)obj + 0x158));
        _ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)obj, 0x1f, 0xfa);
    }
    if (_ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) != 0x1f) {
        return;
    }
    TrySetMode02076ccc(obj, 1);
}
