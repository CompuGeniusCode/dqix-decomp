#include <globaldefs.h>

extern "C" int func_ov000_02161318(void *obj);

// USA: func_ov000_02161300  (semantic: InvokeFieldHandler_02161300)
extern "C" ARM void func_ov000_02161300(void *obj) {
    if (func_ov000_02161318((char*)obj + 0x3760) == 0) {
        return;
    }
}
