#include <globaldefs.h>

static inline int isPositive(int value) {
    return value > 0;
}

// USA: func_0203b438
ARM int GetField0x1cStateIfField0x20Positive(int* obj) {
    int state;
    int value;
    if (!isPositive(obj[8])) {
        return 0;
    }
    value = obj[7];
    state = 1;
    if (value < 0) {
        state = 2;
    }
    if (value > 0) {
        state = 3;
    }
    return state;
}
