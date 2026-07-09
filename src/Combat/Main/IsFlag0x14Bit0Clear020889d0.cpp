#include <globaldefs.h>

// USA: func_020889d0
ARM int IsFlag0x14Bit0Clear020889d0(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
