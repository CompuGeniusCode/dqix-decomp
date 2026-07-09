#include <globaldefs.h>

struct StateBits5ccc_11544 {
    char unk[0x5CCC];
    signed int flag : 1;
};

// USA: func_02011544
ARM void SetFlag0x5cccBit0(struct StateBits5ccc_11544* state) {
    state->flag = 1;
}
