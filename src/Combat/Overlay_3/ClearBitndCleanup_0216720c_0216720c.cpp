// USA: func_ov003_0216720c
#include <globaldefs.h>

extern "C" void func_0204b088(void*, int);

ARM void ClearBitndCleanup_0216720c_0216720c(char* obj) {
    if (*(int*)(obj + 0x464) & 0x40000) {
        func_0204b088(*(char**)(obj + 0x328) + 0x40, 0);
        *(int*)(obj + 0x464) &= ~0x40000;
    }
}
