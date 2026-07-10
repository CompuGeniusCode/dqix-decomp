#include <globaldefs.h>

void InitHandleField0(void);
extern "C" void func_020c6340(int, int, int);
extern "C" void func_020c63a4(void);

// USA: func_020bbbf4
ARM void RunField0ScopedOperation(int a, int b, int c) {
    InitHandleField0();
    func_020c6340(a, b, c);
    func_020c63a4();
}
