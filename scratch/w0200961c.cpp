#include <globaldefs.h>

struct Counter0200961c {
    char pad[2];
    short overflow;
    char pad2;
};

// USA: func_0200961c
extern "C" ARM void IncrementDigitCounter0200961c(struct Counter0200961c* obj, int numDigits) {
    unsigned char* first = (unsigned char*)obj + 5;
    unsigned char* p = first + numDigits - 1;
    unsigned char d;
    for (;;) {
        d = *p;
        if (d < 9) {
            *p = d + 1;
            return;
        }
        if (p == first) {
            *p = 1;
            obj->overflow++;
            return;
        }
        *p = 0;
        p--;
    }
    __builtin_unreachable();
}
