#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_ov011_02184c68(void* obj, int val);

// USA: func_ov011_021874b0
ARM int SetFieldFromGlobal998_021874b0(void* obj) {
    int val = *(int*)((char*)(int)GetGlobalField0x1c020421a0() + 0x998);
    func_ov011_02184c68(obj, val);
    return 1;
}
