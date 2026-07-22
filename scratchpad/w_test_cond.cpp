#include <globaldefs.h>

extern "C" void func_ov000_02171d90(void* entry);
extern "C" void func_ov000_02170db0(void* entry);

// USA: func_ov000_02174428
ARM void TestCond(void* entry) {
    int cond = 0;
    int field4c = *(int*)((char*)entry + 0x4c);
    if (field4c >= 0) {
        if (field4c <= 3) {
            cond = 1;
        }
    }
    if (cond == 0) return;
    func_ov000_02171d90(entry);
    func_ov000_02170db0(entry);
}
