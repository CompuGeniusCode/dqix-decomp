#include <globaldefs.h>

struct BitField020340d4 {
    char pad[0xc2];
    unsigned char lo : 7;
    unsigned char bit7 : 1;
};

// USA: func_020340d4
ARM int GetFlag0x80At0xc2(struct BitField020340d4* p) {
    return p->bit7;
}
