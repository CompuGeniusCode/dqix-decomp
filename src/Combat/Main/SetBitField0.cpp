#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

// USA: func_020e36c4
ARM void SetBitField0(unsigned char* obj, int bit) {
    if (CheckField0NonZero((int*)func_0202ae18())) {
        obj[0] |= 1 << bit;
    }
}
