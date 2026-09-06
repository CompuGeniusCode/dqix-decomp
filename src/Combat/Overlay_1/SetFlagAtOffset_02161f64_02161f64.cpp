#include <globaldefs.h>

extern "C" void* func_02012fe4(void);

// USA: func_ov001_02161f64
ARM int SetFlagAtOffset_02161f64_02161f64(void) {
    unsigned char* p = (unsigned char*)func_02012fe4() + 0x3ec;
    p += 0x2000;
    p[0x261] = 1;
    return 1;
}
