#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_02022d78(void* obj, int code);

// USA: func_020dc3b8
ARM void Notify02022d78WithCode2(void) {
    int base = func_ov017_0218b5b0();
    func_02022d78(*(void**)(base + 0x3000 + 0x6d0), 2);
}
