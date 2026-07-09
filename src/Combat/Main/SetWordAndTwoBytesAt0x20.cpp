#include <globaldefs.h>

struct Fields020b2e28 {
    unsigned char pad0[0x20];   // 0x0..0x1f
    int field20;                // 0x20
    unsigned char field24;      // 0x24
    unsigned char field25;      // 0x25
};

// USA: func_020b2e28
ARM void SetWordAndTwoBytesAt0x20(struct Fields020b2e28* s, int a, int b, unsigned char c, int d) {
    s->field20 = a;
    s->field24 = c;
    s->field25 = d;
}
