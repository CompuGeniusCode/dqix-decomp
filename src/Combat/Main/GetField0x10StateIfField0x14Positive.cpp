#include <globaldefs.h>

static inline int isPositive(int value) {
    return value > 0;
}

// USA: func_0203b400
ARM int GetField0x10StateIfField0x14Positive(int* obj) {
    int state;
    int value;
    if (!isPositive(obj[5])) {
        return 0;
    }
    value = obj[4];
    state = 1;
    if (value < 0) {
        state = 2;
    }
    if (value > 0) {
        state = 3;
    }
    return state;
}
