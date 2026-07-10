#include <globaldefs.h>

// USA: func_02047888
ARM void WriteReg0400048802047888(int a, int b) {
    *(volatile unsigned int*)0x4000488 =
        (unsigned short)(short)(a >> 8) | ((unsigned short)(short)(b >> 8) << 16);
}
