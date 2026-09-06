#include <globaldefs.h>

// USA: func_ov004_02163478  (semantic: CycleFieldState_02163478)
extern "C" ARM void func_ov004_02163478(unsigned char* obj) {
    obj += 0x1000;
    obj[0x8fb] = obj[0x8fa];
    unsigned char v = obj[0x8fa];
    if (v == 0) { obj[0x8fa] = 1; return; }
    if (v == 1) { obj[0x8fa] = 2; return; }
    if (v == 2) { obj[0x8fa] = 0; return; }
}
