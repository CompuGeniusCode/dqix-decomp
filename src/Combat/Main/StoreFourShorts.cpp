#include <globaldefs.h>

struct FourShorts020e12a8 {
    short a;
    short b;
    short c;
    short d;
};

// USA: func_020e12a8
ARM void StoreFourShorts(struct FourShorts020e12a8* dst, short a, short b, short c, short d) {
    dst->a = a;
    dst->b = b;
    dst->c = c;
    dst->d = d;
}
