#include <globaldefs.h>

extern "C" void func_020a620c(void* obj);

// USA: func_ov003_02173788
ARM void UpdateStateFlags_02173788(unsigned char* obj) {
    func_020a620c(obj + 0xd8);
    if (obj[0xef] != 0) {
        return;
    }
    if (obj[0xcb] != 0) {
        obj[0xcb] = 0;
        obj[0xed] = 3;
        obj[0xef] = 0;
    } else if (obj[0xca] != 0) {
        obj[0xed] = 4;
        obj[0xef] = 0;
    }
}
