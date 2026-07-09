#include <globaldefs.h>

struct S_37620 {
    char pad[0x7c];
    unsigned short f7c;
    unsigned short f7e;
    unsigned short f80;
};

// USA: func_02037620
ARM void SetBoundedValuePair(struct S_37620* obj, unsigned short a, unsigned short b) {
    if (b == 0) {
        obj->f7c = a;
        obj->f7e = a;
        obj->f80 = 0;
    } else {
        obj->f7e = a;
        obj->f80 = b;
    }
}
