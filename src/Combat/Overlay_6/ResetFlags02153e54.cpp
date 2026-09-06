#include <globaldefs.h>

struct ResetFlags02153e54Struct {
    short f0;
    unsigned short f2;
};

// USA: func_ov006_02153e54
ARM void ResetFlags02153e54(struct ResetFlags02153e54Struct* s) {
    s->f0 = -1;
    s->f2 &= ~1;
    s->f2 &= ~2;
    s->f2 &= 0xffff0003;
}
