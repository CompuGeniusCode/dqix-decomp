#include <globaldefs.h>

// USA: func_0208869c
ARM int CheckFlag0x14Bit0Clear(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
