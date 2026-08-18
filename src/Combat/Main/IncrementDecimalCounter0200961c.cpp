#include <globaldefs.h>

struct Counter0200961c {
    char pad0[2];
    short total;
};

// USA: func_0200961c  (semantic: IncrementDecimalCounter0200961c)
extern "C" ARM void func_0200961c(struct Counter0200961c* obj, int count) {
    unsigned char* first = (unsigned char*)obj + 5;
    unsigned char* p = first + count - 1;
    for (;;) {
        unsigned char digit = *p;
        if (digit < 9) {
            *p = digit + 1;
            return;
        }
        if (p == first) {
            *p = 1;
            obj->total = obj->total + 1;
            return;
        }
        *p-- = 0;
    }
}
