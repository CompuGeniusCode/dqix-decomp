#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern unsigned short data_02109928[10][2];
extern int GetIntFromVariant02030b0c(Variant02030b0c* p);

// USA: func_02099ac4
ARM int FillVariantShortTable02109928(Variant02030b0c* p) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 2; j++) {
            data_02109928[i][j] = (unsigned short)GetIntFromVariant02030b0c(p);
            p++;
        }
    }
    return 1;
}
