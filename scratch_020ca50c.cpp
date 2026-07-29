#include <globaldefs.h>

struct Block8_020ca50c { unsigned int w[8]; };

// USA: func_020ca50c
ARM void CopyBlock8_020ca50c(Block8_020ca50c* src, Block8_020ca50c* dst) {
    int i;
    for (i = 0; i < 8; i++) {
        dst->w[i] = src->w[i];
    }
}
