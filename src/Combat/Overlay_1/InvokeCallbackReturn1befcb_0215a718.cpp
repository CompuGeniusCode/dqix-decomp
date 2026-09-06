#include <globaldefs.h>

// USA: func_ov001_0215a718
ARM int InvokeCallbackReturn1befcb_0215a718(void (*cb)(void)) {
    if (cb) cb();
    return 0x1befcb;
}
