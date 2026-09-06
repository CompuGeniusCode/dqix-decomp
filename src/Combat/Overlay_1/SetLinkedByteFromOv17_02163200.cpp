#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02163200
ARM int SetLinkedByteFromOv17_02163200(void* obj) {
    char* p = (char*)func_ov017_0218b5b0();
    unsigned char v = *(unsigned char*)(*(char**)(p + 0x3734) + 0x107);
    func_ov017_021d6134(obj, v);
    return 1;
}
