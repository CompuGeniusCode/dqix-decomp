#include <globaldefs.h>

struct Zeroable02169a40 {
    unsigned int a;
    unsigned short b;
    unsigned int c;
    unsigned int d;
};

// USA: func_ov000_02169a40
ARM void ZeroStruct02169a40(struct Zeroable02169a40* s) {
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
}
