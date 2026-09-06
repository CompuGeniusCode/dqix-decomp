#include <globaldefs.h>

// USA: func_020e51fc
ARM unsigned short GetU16At0xc(unsigned char* obj) {
    return *(unsigned short*)(obj + 0xc);
}
