#include <globaldefs.h>

extern "C" int func_020c6f28(int, int, int, int);
unsigned int ClearExMemCntBit0x80(void);

// USA: func_020c6fc0
ARM int Invoke020c6f28ClearExMem0x80(int a) {
    return func_020c6f28(a, 0x27fffe8, (int)ClearExMemCntBit0x80, 1);
}
