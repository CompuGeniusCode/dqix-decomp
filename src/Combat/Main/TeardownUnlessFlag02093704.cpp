#include <globaldefs.h>

extern "C" void* func_0203bd08(void);
extern "C" void func_0203be4c(void* x);
extern "C" void func_0203be40(void* x);

// USA: func_02093704
ARM void TeardownUnlessFlag02093704(int keepAlive) {
    void* x = func_0203bd08();
    func_0203be4c(x);
    if (keepAlive != 0) return;
    func_0203be40(x);
}
