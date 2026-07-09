#include <globaldefs.h>

// USA: func_02089110
ARM int CheckField0x14Bit0Clear02089110(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
