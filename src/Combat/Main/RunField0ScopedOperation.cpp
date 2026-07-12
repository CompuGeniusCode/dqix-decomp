#include <globaldefs.h>
void TransferToSubBgExtPalette(int, unsigned int, int);

void InitHandleField0(void);
extern "C" void func_020c63a4(void);

// USA: func_020bbbf4
ARM void RunField0ScopedOperation(int a, int b, int c) {
    InitHandleField0();
    TransferToSubBgExtPalette((int)(a), (unsigned int)(b), (int)(c));
    func_020c63a4();
}
