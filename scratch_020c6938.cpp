#include <globaldefs.h>

struct Block8_020c6938 { unsigned int w[8]; };

// USA: func_020c6938
ARM void CopyDoubleBlock_020c6938(Block8_020c6938* src, Block8_020c6938* dst) {
    int i;
    for (i = 0; i < 2; i++) {
        *dst = *src;
        src++;
    }
}
