#include <globaldefs.h>

// USA: func_0203983c
ARM void SetBoolFlag0x254(unsigned char* obj, int value) {
    obj[0x254] = value != 0;
}
