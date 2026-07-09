#include <globaldefs.h>

struct ScaledField020b2e3c {
    unsigned char pad0[0xc];    // 0x0..0xb
    unsigned short field0xc;    // 0xc
};

// USA: func_020b2e3c
ARM int GetScaledField0xc(struct ScaledField020b2e3c* s) {
    return s ? (s->field0xc << 3) : 0;
}
