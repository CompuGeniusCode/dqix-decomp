#include <globaldefs.h>

// USA: func_020373e4
ARM int CheckFlag0x6cBit0Clear(unsigned char* obj) {
    return (*(int*)(obj + 0x6c) & 1) == 0;
}
