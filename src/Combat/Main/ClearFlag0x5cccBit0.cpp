#include <globaldefs.h>

struct StateBits5ccc_1155c {
    char unk[0x5CCC];
    signed int flag : 1;
};

// USA: func_0201155c
ARM void ClearFlag0x5cccBit0(struct StateBits5ccc_1155c* state) {
    state->flag = 0;
}
