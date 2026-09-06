#include <globaldefs.h>

// USA: func_ov025_021def30
ARM void IncrementCounterAndReset_021def30(unsigned char* obj) {
    if (*(unsigned short*)(obj+0x770a) == 0) {
        *(int*)(obj+0x55d8) += 1;
    }
    *(int*)(obj+0xeac) = 1;
    *(int*)(obj+0x770c) = 0;
}
