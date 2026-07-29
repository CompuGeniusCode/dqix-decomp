#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215e3e8
ARM int SetFieldFromGlobal9a0_0215e3e8(void* obj) {
    int p = GetGlobalField0x1c020421a0();
    if (p == 0) return 0;
    int v = *(int*)(p + 0x9a0);
    func_ov017_021d6134(obj, v);
    return 1;
}
