#include <globaldefs.h>

extern "C" void func_020c9f2c(int);

// USA: func_020c9fa8
ARM void ResetAllDmaChannels(void) {
    func_020c9f2c(0);
    func_020c9f2c(1);
    func_020c9f2c(2);
    func_020c9f2c(3);
}
