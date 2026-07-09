#include <globaldefs.h>

// USA: func_02053cdc
ARM int IsField0x1b4Or0x1b8Positive(int* obj) {
    return obj[0x6d] > 0 || obj[0x6e] > 0;
}
