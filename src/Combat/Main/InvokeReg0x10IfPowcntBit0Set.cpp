#include <globaldefs.h>

int IsPowcntBit0Set(void);
extern "C" int func_020ce56c(int a, int b, int c);

// USA: func_020ce7e0
ARM int InvokeReg0x10IfPowcntBit0Set(int id) {
    if (IsPowcntBit0Set() == 0) {
        return 0;
    }
    return func_020ce56c(0x10, (unsigned short)id, 0);
}
