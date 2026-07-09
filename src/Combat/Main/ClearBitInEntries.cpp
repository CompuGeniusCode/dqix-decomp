#include <globaldefs.h>

struct BitEntry020e3b08 {
    unsigned char pad[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char pad2;
};

// USA: func_020e3b08
ARM void ClearBitInEntries(struct BitEntry020e3b08* entries, int bit) {
    int i;
    for (i = 0; i < 4; i++, entries++) {
        entries->b5 &= ~(1 << bit);
        entries->b6 &= ~(1 << bit);
    }
}
