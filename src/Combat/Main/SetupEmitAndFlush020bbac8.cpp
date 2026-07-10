#include <globaldefs.h>

extern "C" void func_020c6230(int a, int b, int c);
extern "C" void func_020c6278(int a, int b, int c);
extern "C" void func_020c62e4(void);

// USA: func_020bbac8
ARM void SetupEmitAndFlush020bbac8(int a, int b, int c) {
    func_020c6230(a, b, c);
    func_020c6278(a, b, c);
    func_020c62e4();
}
