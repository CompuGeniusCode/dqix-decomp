#include <globaldefs.h>

extern unsigned char data_ov031_02290cd8;
extern "C" void func_ov031_02227ce4(void);
extern "C" void func_ov031_02233f54(void);
void GetFields181c_02227520(int*, int*);
unsigned int GetField8Low4_02227558(void);
void SetField_022274c0_022274c0(int);

// USA: func_ov031_02234050
extern "C" ARM void func_ov031_02234050(void) {
    if (++data_ov031_02290cd8 < 0xb4) return;
    int b;
    GetFields181c_02227520(NULL, &b);
    unsigned int low4 = GetField8Low4_02227558();
    if (low4 == 0) goto use_default;
    if (low4 != 1) goto use_default;
    if (b == 0) goto use_default;
    SetField_022274c0_022274c0((int)func_ov031_02227ce4);
    return;
use_default:
    SetField_022274c0_022274c0((int)func_ov031_02233f54);
}
