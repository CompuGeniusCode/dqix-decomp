#include <globaldefs.h>

// USA: func_ov000_0216341c
ARM void SetFields0216341c(void* work, unsigned char b1, unsigned char b2, short h) {
    *(int*)((char*)work + 0x6e24) = 1;
    *((unsigned char*)work + 0x6e2a) = b1;
    *((unsigned char*)work + 0x6e2b) = b2;
    *(short*)((char*)work + 0x6e2c) = h;
}
