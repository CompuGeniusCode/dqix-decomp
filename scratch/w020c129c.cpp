#include <globaldefs.h>

struct Layout020c129c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

// USA: func_020c129c
THUMB void InitRange020c129c(Layout020c129c* out, int a1, int a2) {
    out->f0 = a2;
    out->f4 = a1;
    out->f8 = 0;
    out->fc = -a1;
    out->f10 = a2;
    out->f14 = 0;
    out->f18 = 0;
    out->f1c = 0;
    out->f20 = 0x1000;
}
