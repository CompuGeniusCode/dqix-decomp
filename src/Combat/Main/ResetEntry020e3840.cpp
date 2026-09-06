#include <globaldefs.h>

struct Entry020e3840 {
    int f0;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
};

// USA: func_020e3840
ARM void ResetEntry020e3840(struct Entry020e3840* s) {
    s->f0 = -1;
    s->f4 = 0;
    s->f5 = 0;
    s->f6 = 0;
}
