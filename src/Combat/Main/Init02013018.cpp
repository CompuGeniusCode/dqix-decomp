#include <globaldefs.h>

struct InitTarget02013018 {
    unsigned short f0;
    unsigned short f2;
    signed char low7 : 7;
    signed char topBit : 1;
    char pad5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned short f34;
    unsigned short f36;
    unsigned short f38;
    char pad3a[0x54 - 0x3a];
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned int f68;
    unsigned int f6c;
};

// USA: func_02013018
ARM void Init02013018(struct InitTarget02013018 *self) {
    self->f0 = 0xffff;
    self->f2 = 0;
    self->low7 = 0x1f;
    self->topBit = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f6 = 0;
    self->f14 = 0x1000;
    self->f18 = 0x1000;
    self->f1c = 0x1000;
    self->f28 = 0;
    self->f2c = 0;
    self->f30 = 0;
    self->f54 = 0;
    self->f34 = 0;
    self->f36 = 0;
    self->f38 = 0;
    self->f58 = 0;
    self->f5c = 0;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 0;
    self->f6c = 0;
}
