#include <globaldefs.h>

struct SetBitArrayStruct020865b8 {
    char pad[0x111];
    unsigned char bits[0x1000];
};

// USA: func_020865b8
ARM void SetBitInArray020865b8(struct SetBitArrayStruct020865b8* s, int n) {
    s->bits[n / 8] |= 1 << (n % 8);
}
