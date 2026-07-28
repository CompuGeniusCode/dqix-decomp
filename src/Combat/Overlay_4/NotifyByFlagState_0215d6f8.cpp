#include <globaldefs.h>

extern "C" void func_ov011_021848a0(void* obj, int val);
extern char data_ov004_021707d8;

// USA: func_ov004_0215d6f8  (semantic: NotifyByFlagState_0215d6f8)
extern "C" ARM int func_ov004_0215d6f8(void* obj) {
    void* p = *(void**)((char*)&data_ov004_021707d8 + 0x8);
    if (*(unsigned char*)((char*)p + 0x11) == 1) {
        func_ov011_021848a0(obj, 0x236a);
    } else {
        func_ov011_021848a0(obj, 0x38a);
    }
    return 0;
}
