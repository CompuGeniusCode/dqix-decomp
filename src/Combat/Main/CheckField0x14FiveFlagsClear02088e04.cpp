#include <globaldefs.h>

// USA: func_02088e04
ARM int CheckField0x14FiveFlagsClear02088e04(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    if (x & 0x10) {
        return 0;
    }
    if (x & 0x80000) {
        return 0;
    }
    if (x & 0x8) {
        return 0;
    }
    return (x & 0x20) == 0;
}
