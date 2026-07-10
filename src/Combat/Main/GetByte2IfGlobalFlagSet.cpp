#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero(int* obj);

// USA: func_020e37e8
ARM int GetByte2IfGlobalFlagSet(unsigned char* p) {
    if (CheckField0NonZero(func_0202ae18())) {
        return p[2];
    }
    return 1;
}
