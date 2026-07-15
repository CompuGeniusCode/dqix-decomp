#include <globaldefs.h>

// USA: func_ov001_0215a734
ARM int InvokeCallbackReturn1beb10_0215a734(void (*cb)(void)) {
    if (cb) cb();
    return 0x1beb10;
}
