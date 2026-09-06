#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a90
ARM int ForwardField_02161a90_02161a90(void* obj) {
    int* p = *(int**)(func_ov017_0218b5b0() + 0x3000 + 0x734);
    func_ov017_021d6134(obj, p[0x15c / 4]);
    return 1;
}
