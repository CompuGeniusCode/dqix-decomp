#include <globaldefs.h>

// USA: func_0208beb4
ARM void SetFlag0x2IfByte0xd4Not3(unsigned char* obj) {
    if (obj[0xd4] != 3) {
        *(unsigned short*)(obj + 0xda) |= 2;
    }
}
