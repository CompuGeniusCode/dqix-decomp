#include <globaldefs.h>
int RunHandlerWithFallbackDispatch020ce56c(int, int, int);

int IsPowcntBit0Set(void);

// USA: func_020ce7e0
ARM int InvokeReg0x10IfPowcntBit0Set(int id) {
    if (IsPowcntBit0Set() == 0) {
        return 0;
    }
    return RunHandlerWithFallbackDispatch020ce56c((int)(0x10), (int)((unsigned short)id), (int)(0));
}
