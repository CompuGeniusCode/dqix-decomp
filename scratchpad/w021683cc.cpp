#include <globaldefs.h>

extern "C" void func_ov004_0216856c(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_021683cc
ARM int Function_021683cc(void* a1) {
    func_ov004_0216856c(a1);
    func_ov011_021848a0(a1, 2);
    return 0;
}
