#include <globaldefs.h>

// USA: func_ov027_021dad84
ARM int CountU16UntilZero_021dad84(unsigned short *p) {
    unsigned short v = *p++;
    int count = 0;
    if (v != 0) {
        do {
            count++;
            v = *p++;
        } while (v != 0);
    }
    return count;
}
