#include <globaldefs.h>

struct NodeC78 {
    char pad0[0x10];
    struct NodeC78* next;
    char pad14[5];
    unsigned char count;
    unsigned short entries[1];
};

// Forces branches instead of if-conversion for this file's functions.
#pragma optimize_for_size off

// USA: func_020b2c78
ARM void SetBitsForFlaggedEntries020b2c78(unsigned int* bitset, struct NodeC78* node) {
    int i;
    if (node == 0) {
        return;
    }
    do {
        i = 0;
        if (i < node->count) {
            do {
                if (node->entries[i] & 0x100) {
                    bitset[i >> 5] |= 1 << (i & 0x1f);
                }
                i++;
            } while (i < node->count);
        }
        node = node->next;
    } while (node != 0);
}
