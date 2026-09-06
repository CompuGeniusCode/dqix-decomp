#include <globaldefs.h>

struct S_02011430 {
    char unk[0x5cd0];
    unsigned char bits[32];
};

// USA: func_02011430
ARM int GetBit5cd0(struct S_02011430* obj, int a, int b) {
    unsigned int idx = b + (a - 1) * 5;
    unsigned int q = idx / 8;
    unsigned char mask = 1 << (idx - q * 8);
    return (obj->bits[idx / 8] & mask) != 0;
}
