#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215e3b8
ARM int SetFieldFromGlobalByte_0215e3b8_0215e3b8(void* obj) {
    int base = GetGlobalField0x1c020421a0();
    if (base == 0) return 0;
    unsigned char v = *(unsigned char*)(base + 0x19b4);
    func_ov017_021d6134(obj, v);
    return 1;
}
