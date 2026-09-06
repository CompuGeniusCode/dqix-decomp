#include <globaldefs.h>

// USA: func_020d6be4
ARM int InvokeCallbackReturnStatus020d6be4(void (*callback)(void)) {
    if (callback != NULL) {
        callback();
    }
    return 0xffe412c4;
}
