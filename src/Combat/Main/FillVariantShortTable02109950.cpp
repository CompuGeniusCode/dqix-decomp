#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern unsigned short data_02109950[8][2];
extern int GetIntFromVariant02030b0c(Variant02030b0c* p);

// USA: func_02099b20
ARM int FillVariantShortTable02109950(Variant02030b0c* p) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {
            data_02109950[i][j] = (unsigned short)GetIntFromVariant02030b0c(p);
            p++;
        }
    }
    return 1;
}
