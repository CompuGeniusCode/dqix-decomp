#include <globaldefs.h>

struct ResetStruct0218eef0 {
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned char f1c;
    unsigned char pad1d[3];
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned char f2c;
    unsigned char pad2d[3];
    unsigned int f30;
    unsigned short f34;
    unsigned short f36;
    short f38;
    unsigned char f3a;
    unsigned char f3b;
    unsigned char f3c;
    unsigned char f3d;
    unsigned char f3e;
    unsigned char pad3f;
    unsigned short f40;
    unsigned short f42;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned char f50;
    unsigned char pad51[3];
    unsigned int f54;
    unsigned int f58;
};

// USA: func_ov015_0218eef0
ARM void InitCombatFieldStruct0218eef0(ResetStruct0218eef0 *s) {
    int zero = 0;
    int two = 2;
    s->f04 = zero;
    s->f08 = zero;
    s->f0c = zero;
    s->f10 = zero;
    s->f14 = zero;
    s->f18 = zero;
    s->f1c = zero;
    s->f20 = zero;
    s->f24 = zero;
    s->f28 = zero;
    s->f2c = two;
    s->f30 = zero;
    s->f34 = zero;
    s->f36 = zero;
    s->f38 = two - 3;
    s->f3a = zero;
    s->f3b = zero;
    s->f3d = zero;
    s->f3c = zero;
    s->f3e = two;
    s->f40 = 0x1000;
    s->f42 = 0x1000;
    s->f44 = 0x10;
    s->f48 = zero;
    s->f4c = zero;
    s->f00 = zero;
    s->f50 = zero;
    s->f54 = zero;
    s->f58 = zero;
}
