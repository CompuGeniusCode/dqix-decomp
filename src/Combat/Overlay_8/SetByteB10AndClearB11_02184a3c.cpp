#include <globaldefs.h>

// USA: func_ov008_02184a3c
ARM void SetByteB10AndClearB11_02184a3c(char* obj, unsigned char val) {
    obj[0xb10] = val;
    obj[0xb11] = 0;
}
