#include <globaldefs.h>

struct FlaggedEntry020B4204 {
    char pad0[0x10];
    struct FlaggedEntry020B4204* next;
    char pad14[5];
    unsigned char count;
    unsigned short flags[1];
};

#pragma optimize_for_size off
// USA: func_020b4204
ARM void SetBitsForFlaggedEntries(unsigned int* bits, struct FlaggedEntry020B4204* node) {
    int j;
    if (node == NULL) return;
    do {
        j = 0;
        if (j < node->count) {
            do {
                if (node->flags[j] & 0x100) {
                    bits[j >> 5] |= 1 << (j & 0x1f);
                }
                j++;
            } while (j < node->count);
        }
        node = node->next;
    } while (node != NULL);
}
