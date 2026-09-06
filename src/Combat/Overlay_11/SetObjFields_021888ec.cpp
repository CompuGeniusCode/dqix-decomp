#include <globaldefs.h>

extern "C" void func_ov017_021d4cc0(void* obj, void* a, int b);
extern int data_ov011_021889a0;

// USA: func_ov011_021888ec
ARM void SetObjFields_021888ec(void* obj) {
    func_ov017_021d4cc0(obj, &data_ov011_021889a0, 0x73);
}
