#include <globaldefs.h>

// USA: func_0200961c
#pragma optimize_for_size off
ARM void IncrementDigitCounterWithCarry_0200961c(void* obj, int length) {
    unsigned char* first = (unsigned char*)obj + 5;
    unsigned char* p = first + length - 1;
    for (;;) {
        unsigned char digit = *p;
        if (digit < 9) {
            *p = digit + 1;
            return;
        }
        if (p == first) {
            *p = 1;
            *(short*)((char*)obj + 2) += 1;
            return;
        }
        *p = 0;
        p--;
    }
}
