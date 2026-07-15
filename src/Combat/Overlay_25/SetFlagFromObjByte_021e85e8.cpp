#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov025_021e85e8
ARM int SetFlagFromObjByte_021e85e8(unsigned char* obj) {
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    base[0x4488] = 1;
    unsigned char flag = obj[8];
    unsigned char v = 1;
    if (flag == 0) {
        v = 0;
    }
    base[0x4488] = v;
    return 1;
}
