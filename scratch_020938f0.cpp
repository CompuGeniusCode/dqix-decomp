#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void ClearRegion02093980(char* obj);

// USA: func_020938f0
ARM void ResetSixteenRegionsAndFlags020938f0(char* obj) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        ClearRegion02093980(obj + i * 0x34);
        ClearRegion02093980(obj + 0x1a0 + i * 0x34);
    }
    *(unsigned int*)(obj + 0x340) = 0xffffffff;
    *(unsigned int*)(obj + 0x344) = 0;
    memset(obj + 0x348, 0, 0x80);
    obj[0x3c8] = (obj[0x3c8] & ~0x7f) | 0x80;
    obj[0x3c9] &= ~1;
    obj[0x3ca] = 0;
    obj[0x3cb] = 0;
    obj[0x3cc] = 0;
    obj[0x3cd] = 8;
}
