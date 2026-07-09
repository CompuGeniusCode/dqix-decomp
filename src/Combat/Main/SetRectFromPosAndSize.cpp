#include <globaldefs.h>

struct Rect020e2d2c {
    unsigned char pad[0x14];
    int f14;
    int f18;
    int f1c;
    int f20;
};

// USA: func_020e2d2c
ARM void SetRectFromPosAndSize(struct Rect020e2d2c* s, int a, int b, int c, int d) {
    s->f14 = a;
    s->f18 = b;
    s->f1c = a + c;
    s->f20 = b + d;
}
