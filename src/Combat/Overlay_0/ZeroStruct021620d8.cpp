#include <globaldefs.h>

struct ZeroableStruct021620d8 {
    unsigned char a;
    unsigned char b;
    unsigned short c;
    unsigned int d;
};

// USA: func_ov000_021620d8
ARM void ZeroStruct021620d8(struct ZeroableStruct021620d8* s) {
    s->c = 0;
    s->a = 0;
    s->b = 0;
    s->d = 0;
}
