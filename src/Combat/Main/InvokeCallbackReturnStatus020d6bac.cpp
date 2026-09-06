#include <globaldefs.h>

// USA: func_020d6bac
ARM int InvokeCallbackReturnStatus020d6bac(void (*callback)(void)) {
    if (callback != NULL) {
        callback();
    }
    return 0xffe41136;
}
