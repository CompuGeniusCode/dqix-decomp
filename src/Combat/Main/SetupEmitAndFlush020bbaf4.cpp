#include <globaldefs.h>

extern "C" void func_020c60d8(int a, int b, int c);
extern "C" void func_020c6178(int a, int b, int c);
extern "C" void func_020c61e8(void);

// USA: func_020bbaf4
ARM void SetupEmitAndFlush020bbaf4(int a, int b, int c) {
    func_020c60d8(a, b, c);
    func_020c6178(a, b, c);
    func_020c61e8();
}
