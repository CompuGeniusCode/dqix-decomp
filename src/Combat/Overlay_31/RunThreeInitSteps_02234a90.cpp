#include <globaldefs.h>

extern "C" void func_ov031_02234aa4(void);
extern "C" void func_ov031_02234adc(void);
extern "C" void func_ov031_02234ae0(void);

// USA: func_ov031_02234a90
ARM void RunThreeInitSteps_02234a90(void) {
    func_ov031_02234aa4();
    func_ov031_02234adc();
    func_ov031_02234ae0();
}
