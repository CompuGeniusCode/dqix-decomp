#include <globaldefs.h>

// USA: func_ov000_0216872c
ARM void SetByteFields0x77d3And0x77d4(void* obj, int a, int b) {
    *(unsigned char*)((char*)obj + 0x77d3) = (unsigned char)a;
    *(unsigned char*)((char*)obj + 0x77d4) = (unsigned char)b;
}
