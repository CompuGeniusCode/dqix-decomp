#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern short data_02109970[8][4];

// USA: func_02099b7c
ARM int DecodeVariantsInto8x4Table(struct Variant02030b0c* arg) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            data_02109970[i][j] = GetIntFromVariant02030b0c(arg);
            arg = (struct Variant02030b0c*)((char*)arg + 8);
        }
    }
    return 1;
}
