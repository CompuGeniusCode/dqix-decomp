#include <globaldefs.h>

struct Canvas0204e998 {
    char pad0[0x9c];        // 0x00
    int _9c;                // 0x9c
    unsigned int a0;        // 0xa0
    char pad_a4[4];         // 0xa4
    short a8;               // 0xa8 (width)
    short aa;               // 0xaa (height)
    char pad_ac[0x19];      // 0xac..0xc4
    unsigned char c5;       // 0xc5 (flags)
    char pad_c6[0xe];       // 0xc6..0xd3
    unsigned short *d4;     // 0xd4 (buffer)
};

// USA: func_0204e998
ARM void FillIndexBuffer0204e998(struct Canvas0204e998 *s) {
    unsigned short v;
    unsigned short *p;
    short j, i;
    if ((s->c5 & 1) && s->d4 != NULL) {
        p = s->d4;
        v = s->a0 >> 5;
        for (j = 0; j < s->aa; j++) {
            for (i = 0; i < s->a8; i++) {
                p[i] = v;
                v++;
            }
            p += s->a8;
        }
        s->_9c++;
    }
}
