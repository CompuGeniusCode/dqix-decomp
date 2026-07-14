#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);
extern "C" int sprintf(void* dst, void* fmt, int val);
extern "C" int func_020420e8(void* builder, void* obj);
extern char data_020f0046;

// USA: func_02042658
ARM void FormatAbsIntToString02042658(void* obj, int value) {
    char buf[0x20];
    func_0200f374(buf, 0x20);
    if (value < 0) value = -value;
    sprintf(buf, &data_020f0046, value);
    func_020420e8(buf, obj);
}
