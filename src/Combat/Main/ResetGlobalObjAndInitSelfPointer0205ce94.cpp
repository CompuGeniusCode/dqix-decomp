#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_02042b10(void* a, void* b);
void InitSelfPointer(unsigned char* base);

// USA: func_0205ce94
ARM void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    func_02042b10(base, p + 0xb4);
    void* q = *(void**)(base + 0x1e20);
    if (q != NULL) {
        *(int*)((char*)q + 8) = 0;
    }
    InitSelfPointer(base);
}
