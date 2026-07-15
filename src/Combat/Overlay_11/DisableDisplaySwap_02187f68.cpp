#include <globaldefs.h>

extern "C" void func_ov011_02187f4c(int enable);

// USA: func_ov011_02187f68
ARM int DisableDisplaySwap_02187f68(void) {
    func_ov011_02187f4c(0);
    return 1;
}
