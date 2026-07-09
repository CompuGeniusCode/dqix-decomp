#include <globaldefs.h>

// USA: func_0207e07c
ARM int StoreValueIfNonZero(int* dst, int value) {
    if (value == 0) {
        return 0;
    }
    *dst = value;
    return 1;
}
