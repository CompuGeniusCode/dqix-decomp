#include <globaldefs.h>

// USA: func_ov000_02163b60
ARM void ZeroFieldAndShortTriple0x6e2e(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[0x6e2e] = 0;
    for (int i = 0; i < 3; i++) *(unsigned short*)(p + 0x6e30 + i * 2) = 0;
}
