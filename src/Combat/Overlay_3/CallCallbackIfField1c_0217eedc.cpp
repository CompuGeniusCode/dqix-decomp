#include <globaldefs.h>

extern "C" void func_ov009_02184c30(void);

// USA: func_ov003_0217eedc
ARM void CallCallbackIfField1c_0217eedc(int* obj) {
    if (obj[7] != 0) {
        func_ov009_02184c30();
    }
}
