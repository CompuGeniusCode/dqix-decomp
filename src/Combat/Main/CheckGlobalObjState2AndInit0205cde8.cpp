#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_02042b10(void* a, void* b);
int CheckField0x440State2(unsigned char* obj);
void InitSelfPointer(unsigned char* base);

// USA: func_0205cde8
ARM int CheckGlobalObjState2AndInit0205cde8(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    func_02042b10(base, p + 0xb4);
    int result = CheckField0x440State2(base + 0x19e0) != 0;
    InitSelfPointer(base);
    return result;
}
