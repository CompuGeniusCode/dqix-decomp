#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_021652bc
ARM int CheckFieldAndEnqueue_021652bc_021652bc(void* obj) {
    if (*(int*)((char*)GetGlobalField0x1c020421a0() + 0x998) == 0) {
        func_ov011_021848a0(obj, 0x65);
    }
    return 0;
}
