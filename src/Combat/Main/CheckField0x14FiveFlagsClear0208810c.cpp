#include <globaldefs.h>

// USA: func_0208810c
ARM int CheckField0x14FiveFlagsClear0208810c(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    if (x & 0x1000000) {
        return 0;
    }
    if (x & 0x10) {
        return 0;
    }
    if (x & 0x80000) {
        return 0;
    }
    return (x & 0x8) == 0;
}
