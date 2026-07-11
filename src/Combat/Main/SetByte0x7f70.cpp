#include <globaldefs.h>

// USA: func_02012028
ARM void SetByte0x7f70(void* obj, unsigned char value) {
    ((unsigned char*)obj + 0x7000)[0xf70] = value;
}
