#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern short data_021099b0[8][8];

// USA: func_02099bd8
ARM int DecodeVariantsInto8x8Table(struct Variant02030b0c* arg) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            data_021099b0[i][j] = GetIntFromVariant02030b0c(arg);
            arg = (struct Variant02030b0c*)((char*)arg + 8);
        }
    }
    return 1;
}
