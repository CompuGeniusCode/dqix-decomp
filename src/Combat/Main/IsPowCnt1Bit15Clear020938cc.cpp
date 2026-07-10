#include <globaldefs.h>

// USA: func_020938cc
ARM int IsPowCnt1Bit15Clear020938cc() {
    return ((*(unsigned short*)0x4000304 & 0x8000) >> 15) != 1;
}
