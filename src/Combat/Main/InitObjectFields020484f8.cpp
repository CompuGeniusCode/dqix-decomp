#include <globaldefs.h>

struct IntField0x64_020377c4;
struct IntField0x68_020377b4;
struct Shorts5c_374e0;

extern "C" void _ZN8Object3D8SetScaleEiii(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" void _ZN8Object3D9SetRadiusEi(struct IntField0x64_020377c4*, int);
extern "C" void _ZN8Object3D9SetHeightEi(struct IntField0x68_020377b4*, int);
extern "C" int _ZNK8Object3D8GetFlagsEv(unsigned char* obj);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void* _ZN8Object3D27UseRenderConfigDiffuseColorEv(void* obj);

struct AcTarget020484f8 {
    char unk0[0x8];
    short at8;
    short unkA;
    short atc;
    short ate;
};

struct Input020484f8 {
    struct AcTarget020484f8* ac;
    unsigned int val4;
    unsigned int val8;
};

// USA: func_020484f8
ARM void InitObjectFields020484f8(unsigned char* self, struct Input020484f8* in) {
    *(unsigned int*)(self + 0xb0) = in->val4;
    *(struct AcTarget020484f8**)(self + 0xac) = in->ac;
    *(unsigned int*)(self + 0xb4) = in->val8;
    _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)self, 0x10a, 0x10a, 0x10a);
    _ZN8Object3D9SetRadiusEi((struct IntField0x64_020377c4*)self, (*(struct AcTarget020484f8**)(self + 0xac))->atc << 2);
    _ZN8Object3D9SetHeightEi((struct IntField0x68_020377b4*)self, (*(struct AcTarget020484f8**)(self + 0xac))->ate);
    if ((*(struct AcTarget020484f8**)(self + 0xac))->at8 == 0x140) {
        _ZN8Object3D10EnableFlagEi(self, 0x20000000);
    }
    if (_ZNK8Object3D8GetFlagsEv(self) & 0x20000000) return;
    _ZN8Object3D27UseRenderConfigDiffuseColorEv(self);
}
