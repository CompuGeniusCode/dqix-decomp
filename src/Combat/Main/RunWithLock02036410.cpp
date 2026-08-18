#include <globaldefs.h>

extern "C" void _Z17LockResourceMutexv(void);
extern "C" int func_0203643c(int a, int b);
extern "C" void _Z19UnlockResourceMutexv(void);

// USA: func_02036410
ARM int RunWithLock02036410(int a, int b) {
    int r;
    _Z17LockResourceMutexv();
    r = func_0203643c(a, b);
    _Z19UnlockResourceMutexv();
    return r;
}
