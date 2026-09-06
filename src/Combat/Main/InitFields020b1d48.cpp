#include <globaldefs.h>

struct Fields020b1d48 {
    int field0;             // 0x0
    int field4;             // 0x4
    int field8;             // 0x8
    unsigned char fieldC;   // 0xc
    unsigned char padD[3];  // 0xd..0xf
    int field10;            // 0x10
    int field14;            // 0x14
};

// USA: func_020b1d48
ARM void InitFields020b1d48(struct Fields020b1d48* s, int a, int b, int c, int d, int e, int f) {
    s->field4 = b;
    s->field8 = c;
    s->fieldC = d;
    s->field0 = a;
    s->field14 = e;
    s->field10 = f;
}
