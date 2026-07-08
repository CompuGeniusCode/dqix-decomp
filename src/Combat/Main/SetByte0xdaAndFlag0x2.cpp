#include <globaldefs.h>

// USA: func_02050440
ARM void SetByte0xdaAndFlag0x2(unsigned char* obj, int val) {
    obj[0xda] = val;
    obj[0xd8] |= 2;
}
