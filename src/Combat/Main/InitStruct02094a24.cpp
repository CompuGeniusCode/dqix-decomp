#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02094a24 {
    int f0, f4, f8, fc, f10;
    int arr[8];
    int f34, f38, f3c, f40;
    unsigned char buf[0x10];
    unsigned char f54, f55, f56, f57;
    unsigned char pad58[9];
    unsigned char f61, f62, f63, f64;
};

// USA: func_02094a24
ARM void InitStruct02094a24(struct Struct02094a24* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    for (int i = 0; i < 8; i++) {
        s->arr[i] = -1;
    }
    s->f3c = -1;
    s->f40 = -1;
    s->f38 = -1;
    s->f34 = -1;
    memset(s->buf, 0, 0x10);
    s->f55 = 0;
    s->f54 = 0;
    s->f56 = 1;
    s->f57 = 0;
    s->f62 = 0;
    s->f61 = 0;
    s->f63 = 0;
    s->f64 = 0;
}
