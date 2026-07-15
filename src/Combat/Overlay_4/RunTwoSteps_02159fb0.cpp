#include <globaldefs.h>

extern "C" void func_ov004_0215951c(int a);
extern "C" void func_ov004_02159ce0(int a);

// USA: func_ov004_02159fb0
ARM int RunTwoSteps_02159fb0(int a) {
    func_ov004_0215951c(a);
    func_ov004_02159ce0(a);
    return 0;
}
