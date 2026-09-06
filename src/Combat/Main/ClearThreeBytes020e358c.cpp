#include <globaldefs.h>

struct Bytes020e358c {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
};

// USA: func_020e358c
ARM void ClearThreeBytes020e358c(struct Bytes020e358c* s) {
    s->f0 = 0;
    s->f1 = 0;
    s->f2 = 0;
}
