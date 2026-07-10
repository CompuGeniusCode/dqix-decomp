#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" int func_0203643c(int a, int b);
extern "C" void func_020d974c(void);

// USA: func_02036410
ARM int RunWithLock02036410(int a, int b) {
    int r;
    func_020d970c();
    r = func_0203643c(a, b);
    func_020d974c();
    return r;
}
