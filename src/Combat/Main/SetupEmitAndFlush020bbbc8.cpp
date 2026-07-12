#include <globaldefs.h>
void TransferToSubObjExtPalette(int, unsigned int, int);

void InitHandleField18(void);
extern "C" void func_020c6460(void);

// USA: func_020bbbc8
ARM void SetupEmitAndFlush020bbbc8(int a, int b, int c) {
    InitHandleField18();
    TransferToSubObjExtPalette((int)(a), (unsigned int)(b), (int)(c));
    func_020c6460();
}
