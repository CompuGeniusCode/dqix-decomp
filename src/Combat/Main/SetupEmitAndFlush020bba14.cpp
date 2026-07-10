#include <globaldefs.h>

extern "C" void func_020c676c(int a, int b, int c);
extern "C" void func_020c6864(int a, int c);
extern "C" void func_020c68d0(void);

// USA: func_020bba14
ARM void SetupEmitAndFlush020bba14(int a, int b, int c) {
    func_020c676c(a, b, c);
    func_020c6864(a, c);
    func_020c68d0();
}
