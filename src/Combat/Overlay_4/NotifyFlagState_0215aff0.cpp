#include <globaldefs.h>

struct Struct021707d8_0215aff0 { char pad[0x8]; unsigned char* ptr; };
extern Struct021707d8_0215aff0 data_ov004_021707d8;
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215aff0  (semantic: NotifyFlagState_0215aff0)
extern "C" ARM int func_ov004_0215aff0(void* a) {
    if (data_ov004_021707d8.ptr[0x6e] == 1) {
        func_ov011_021848a0(a, 0x39c);
    } else {
        func_ov011_021848a0(a, 0x39b);
    }
    return 0;
}
