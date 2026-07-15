#include <globaldefs.h>

extern "C" void func_ov011_02187f4c(int enable);

// USA: func_ov011_02187f38
ARM int EnableDisplaySwap_02187f38(void) {
    func_ov011_02187f4c(1);
    return 1;
}
