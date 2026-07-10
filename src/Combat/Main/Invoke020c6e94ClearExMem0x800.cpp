#include <globaldefs.h>

int Invoke020c6e48Mode0(int, int, int);
unsigned int ClearExMemCntBit0x800(void);

// USA: func_020c7010
ARM int Invoke020c6e94ClearExMem0x800(int a) {
    return Invoke020c6e48Mode0(a, 0x27fffe0, (int)ClearExMemCntBit0x800);
}
