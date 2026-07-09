#include <globaldefs.h>

// USA: func_02089160
ARM int CheckField0x14Bit0Clear02089160(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
