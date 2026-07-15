#include <globaldefs.h>

extern "C" void func_ov009_02184bbc(void);

// USA: func_ov003_0217eec4
ARM void CallCallbackIfField1c_0217eec4(int* obj) {
    if (obj[7] != 0) {
        func_ov009_02184bbc();
    }
}
