#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_0200961c
ARM void func_0200961c(void *obj, int count) {
    unsigned char *digits = (unsigned char*)obj + 5;
    unsigned char *p = digits + count - 1;
    for (;;) {
        unsigned char d = *p;
        if (d < 9) {
            *p = d + 1;
            return;
        }
        if (p == digits) {
            *p = 1;
            *(short*)((char*)obj + 2) += 1;
            return;
        }
        *p = 0;
        p--;
    }
}
