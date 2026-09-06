#include <globaldefs.h>

void ClearRegion02093980(char* obj);

// USA: func_02093a14
ARM void ResetEightRegionsAndFlags(char* obj) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        ClearRegion02093980(obj + i * 0x34);
    }
    obj[0x3cb] = 0;
    ((unsigned char*)obj)[0x3cd] &= ~4;
}
