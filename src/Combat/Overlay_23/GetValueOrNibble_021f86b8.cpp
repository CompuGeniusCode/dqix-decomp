#include <globaldefs.h>

struct Bitfield021f86b8 {
    char pad[0x44];
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
    unsigned char flag : 1;
};

// USA: func_ov023_021f86b8
ARM unsigned int GetValueOrNibble_021f86b8(struct Bitfield021f86b8* obj) {
    unsigned char result;
    if (obj->flag) {
        result = 5;
    } else {
        result = obj->hiNibble;
    }
    return result & 0xff;
}
