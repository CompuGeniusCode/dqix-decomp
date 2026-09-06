#include <globaldefs.h>

void RunTwoStepUpdate_0223d0a4();
extern "C" void func_ov031_0223e168(int);
extern "C" void func_ov031_0222b168(void);
extern "C" void func_ov031_0222b1a4(void);

// USA: func_ov031_0222b36c
ARM void RunUpdateAndTwoChecks_0222b36c(void) {
    RunTwoStepUpdate_0223d0a4();
    func_ov031_0223e168(0);
    func_ov031_0222b168();
    func_ov031_0222b1a4();
}
