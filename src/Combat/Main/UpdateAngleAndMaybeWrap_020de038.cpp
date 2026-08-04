#include <globaldefs.h>

extern "C" int func_020c3260(int);
extern "C" float func_0200c700(int);
int HwDivideRounded020c2bf4(unsigned int, unsigned int);

struct Obj020de038 {
    char pad0[4];
    unsigned char byte4;
    char pad1[0xb];
    int field_0x10;
    char pad2[8];
    int field_0x1c;
};

// USA: func_020de038  (semantic: UpdateAngleAndMaybeWrap_020de038)
extern "C" ARM void func_020de038(struct Obj020de038* self) {
    float t;
    int fixedVal;
    int divided;

    self->field_0x1c = self->field_0x1c + 0x800;
    t = func_0200c700(func_020c3260(self->field_0x1c)) / 4294967296.0f;
    fixedVal = (int)(t * 4096.0f);
    divided = HwDivideRounded020c2bf4(
        (unsigned int)(((long long)(0xc800 - self->field_0x1c) * fixedVal + 0x800) >> 12), 0x3000);
    self->field_0x10 = (int)((float)divided / 4096.0f);
    if (self->field_0x1c >= 0xc800) {
        self->field_0x1c = 0;
        self->byte4 = 1;
    }
}
