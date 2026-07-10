#include <globaldefs.h>

extern unsigned int data_0210a090[];

// USA: func_020b38b0
ARM void PackTriple10BitField020b38b0(int idx, int x, int y, int z) {
    data_0210a090[idx] =
        ((x >> 3) & 0x3ff) |
        (((y >> 3) & 0x3ff) << 10) |
        (((z >> 3) & 0x3ff) << 20) |
        (idx << 30);
}
