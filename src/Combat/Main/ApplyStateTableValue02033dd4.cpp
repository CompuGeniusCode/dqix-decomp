#include <globaldefs.h>

extern signed char data_020ef9c4[][0xd];
extern "C" void func_02033ba0(void* obj, int value);

// USA: func_02033dd4
ARM void ApplyStateTableValue02033dd4(unsigned char* obj) {
    if (obj[0xbe] >= 9) return;
    if (obj[0xc0] >= 0xc) obj[0xc0] = 0;
    func_02033ba0(obj, data_020ef9c4[obj[0xbe]][obj[0xc0]]);
}
