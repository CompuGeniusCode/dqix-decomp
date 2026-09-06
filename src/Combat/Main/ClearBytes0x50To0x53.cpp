#include <globaldefs.h>

// USA: func_02012780
ARM void ClearBytes0x50To0x53(unsigned char* obj) {
    obj[0x52] = 0;
    obj[0x53] = 0;
    obj[0x51] = 0;
    obj[0x50] = 0;
}
