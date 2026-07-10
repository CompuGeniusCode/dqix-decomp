#include <globaldefs.h>

extern "C" int func_020c6ea4(int, int, int, int);
unsigned int SetExMemCntBit0x80(void);

// USA: func_020c6f94
ARM int Invoke020c6ea4SetExMem0x80(int a) {
    return func_020c6ea4(a, 0x27fffe8, (int)SetExMemCntBit0x80, 1);
}
