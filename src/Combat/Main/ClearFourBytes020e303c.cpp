#include <globaldefs.h>

struct Bytes020e303c {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020e303c
ARM void ClearFourBytes020e303c(struct Bytes020e303c* s) {
    s->f0 = 0;
    s->f1 = 0;
    s->f2 = 0;
    s->f3 = 0;
}
