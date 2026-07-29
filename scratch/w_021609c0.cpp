#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_020457e0();
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_021609c0
ARM int SetFieldFromFunc020457e0_021609c0(void* self) {
    GetGlobalField0x1c020421a0();
    int v = func_020457e0();
    func_ov017_021d6134(self, v);
    return 1;
}
