#include <globaldefs.h>

// USA: func_020ca390
ARM void FillHalfwords020ca390(unsigned short val, char* dst, int n) {
    int i = 0;
    while (i < n) {
        *(unsigned short*)(dst + i) = val;
        i += 2;
    }
}
