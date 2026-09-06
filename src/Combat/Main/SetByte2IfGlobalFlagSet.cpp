#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero(int* obj);

// USA: func_020e3778
ARM void SetByte2IfGlobalFlagSet(unsigned char* p) {
    if (CheckField0NonZero(func_0202ae18())) {
        p[2] = 1;
    }
}
