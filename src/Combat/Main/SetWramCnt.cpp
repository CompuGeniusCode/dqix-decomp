#include <globaldefs.h>

// USA: func_020c9bfc
ARM void SetWramCnt(unsigned char value) {
    *(unsigned char*)0x4000247 = value;
}
