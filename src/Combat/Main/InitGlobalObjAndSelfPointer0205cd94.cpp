#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_02042b10(void* a, void* b);
int CheckField0x440State2(unsigned char* obj);
void InitSelfPointer(unsigned char* base);

// USA: func_0205cd94
ARM void InitGlobalObjAndSelfPointer0205cd94(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    func_02042b10(base, p + 0xb4);
    if (CheckField0x440State2(base + 0x19e0) == 0) {
        *(int*)((char*)*(int**)(base + 0x1e20) + 0x8) = 2;
        *(int*)((char*)*(int**)(base + 0x1e20) + 0x14) = 0x1000;
    }
    InitSelfPointer(base);
}
