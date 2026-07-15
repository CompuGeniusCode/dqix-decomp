#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void func_02017c58(void*);
extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov001_02163dc8
ARM int SetFlagInIndirectField_02163dc8(void) {
    func_02017c58(func_02012fe4());
    char* p = *(char**)((func_ov017_0218b5b0() + 0x3000) + 0xb5c);
    p[8] = 1;
    return 1;
}
