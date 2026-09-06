#include <globaldefs.h>

extern unsigned char data_ov031_02290cd8;
ARM void GetFields181c_02227520(int* a, int* b);
ARM unsigned int GetField8Low4_02227558(void);
ARM void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_02227ce4(void);
extern "C" void func_ov031_02233f54(void);

// USA: func_ov031_02234050  (semantic: DispatchByField8Low4_02234050)
extern "C" ARM void func_ov031_02234050(void) {
    unsigned char c = ++data_ov031_02290cd8;
    if (c < 0xb4) return;

    int idx;
    GetFields181c_02227520(NULL, &idx);
    unsigned int v = GetField8Low4_02227558();
    if (v != 0 && v == 1 && idx != 0) {
        SetField_022274c0_022274c0((int)func_ov031_02227ce4);
    } else {
        SetField_022274c0_022274c0((int)func_ov031_02233f54);
    }
}
