#include <globaldefs.h>

// USA: func_020ca3b8
ARM void CopyHalfwordsLoop020ca3b8(volatile char* src, volatile char* dst, int n) {
    int i;
    unsigned short tmp;
    for (i = 0; i < n; i += 2) {
        tmp = *(volatile unsigned short*)(src + i);
        *(volatile unsigned short*)(dst + i) = tmp;
    }
}
