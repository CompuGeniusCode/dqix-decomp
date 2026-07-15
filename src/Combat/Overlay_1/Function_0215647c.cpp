#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov001_0215647c
ARM int Function_0215647c(void* ctx) {
    if (*((unsigned char*)ctx + 0xfc) != 0) return 0xa;
    if (*((unsigned char*)func_ov017_0218b5b0() + 0x42e2) != 0) return 0xa;
    return *(unsigned short*)((char*)ctx + 0xa);
}
