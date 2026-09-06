#include <globaldefs.h>

// USA: func_020263c8
ARM void SetBoolFlag020263c8(unsigned char* obj, int value) {
    obj[0x778] = value != 0;
}
