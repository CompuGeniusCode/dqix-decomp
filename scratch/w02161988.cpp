#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02161988
ARM int SetWorkFlagField105Bit0_02161988(void* obj) {
    unsigned char* work = (unsigned char*)func_02012fe4();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0)
        work[0x105] &= ~1;
    else
        work[0x105] |= 1;
    return 1;
}
