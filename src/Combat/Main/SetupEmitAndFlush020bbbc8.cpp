#include <globaldefs.h>

void InitHandleField18(void);
extern "C" void func_020c63fc(int a, int b, int c);
extern "C" void func_020c6460(void);

// USA: func_020bbbc8
ARM void SetupEmitAndFlush020bbbc8(int a, int b, int c) {
    InitHandleField18();
    func_020c63fc(a, b, c);
    func_020c6460();
}
