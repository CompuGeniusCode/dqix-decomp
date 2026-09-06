#include <globaldefs.h>

struct Entry020984dc {
    unsigned char pad0[0xc];
    unsigned int wc_lo : 4;
    unsigned int typeField : 4;
    unsigned int wc_hi : 24;
    unsigned int w10;
    unsigned char pad14[0xe8 - 0x14];
};

// USA: func_020984dc
ARM int CollectEntriesByType020984dc(struct Entry020984dc* base, int type, struct Entry020984dc** out) {
    int count;
    int i;
    if (out == NULL) {
        return 0;
    }
    if (type >= 0xb) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 0x1e; i++) {
        struct Entry020984dc* e = &base[i];
        if (e->w10 >> 2) {
            if (e->typeField == type) {
                out[count] = e;
                count++;
                if (count >= 6) {
                    break;
                }
            }
        }
    }
    return count;
}
