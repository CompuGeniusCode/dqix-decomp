#include <globaldefs.h>

// USA: func_020e25cc
ARM void ResetBytes020e25cc(signed char* p) {
    p[0x14] = p[0x16];
    p[0x15] = -1;
    p[0x17] = 0;
}
