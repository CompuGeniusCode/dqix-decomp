#include <globaldefs.h>

extern "C" int func_ov031_02222adc(void *buf);
extern "C" void func_020c9be0(void);
extern "C" void func_ov031_02236250(void *buf);

// USA: func_ov031_02227c84
ARM void ValidateAndProcessBuffer_02227c84(void) {
    char buf[0xe8];
    if (func_ov031_02222adc(buf) != 1) {
        func_020c9be0();
    }
    func_ov031_02236250(buf);
}
