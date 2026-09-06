#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern short data_021099b0[8][8];

// USA: func_02099bd8
ARM int DecodeVariantsInto8x8Table(struct Variant02030b0c* arg) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            data_021099b0[i][j] = _ZNK6Script9Parameter5ToIntEv(arg);
            arg = (struct Variant02030b0c*)((char*)arg + 8);
        }
    }
    return 1;
}
