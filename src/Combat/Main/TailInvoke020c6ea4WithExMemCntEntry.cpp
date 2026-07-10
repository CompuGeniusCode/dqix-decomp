#include <globaldefs.h>

extern int Invoke020c6ea4Mode0(int, int, int);
extern unsigned int SetExMemCntBit0x800(void);

// USA: func_020c702c
ARM int TailInvoke020c6ea4WithExMemCntEntry(int a) {
    return Invoke020c6ea4Mode0(a, 0x27fffe0, (int)SetExMemCntBit0x800);
}
