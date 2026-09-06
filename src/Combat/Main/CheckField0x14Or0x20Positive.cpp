#include <globaldefs.h>

static inline int isPositive(int value) {
    return value > 0;
}

// USA: func_0203b3c0
ARM int CheckField0x14Or0x20Positive(int* obj) {
    if (isPositive(obj[5]) || isPositive(obj[8])) {
        return 1;
    }
    return 0;
}
