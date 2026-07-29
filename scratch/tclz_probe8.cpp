#include <globaldefs.h>

// USA: func_020ca3b8
ARM void ProbeLoop8(unsigned short* src, unsigned short* dst, int n) {
    int i = 0;
    while (i < n) {
        *(unsigned short*)((char*)dst + i) = *(unsigned short*)((char*)src + i);
        i += 2;
    }
}
