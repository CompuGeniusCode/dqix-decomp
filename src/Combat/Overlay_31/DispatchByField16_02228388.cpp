#include <globaldefs.h>

int GetField16_02222e0c(void);
extern "C" int func_ov031_02236878(int index);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02227ce4(void);
extern "C" void func_ov031_0222855c(void);
void RegisterCallback_022283d8(void);

// USA: func_ov031_02228388  (semantic: DispatchByField16_02228388)
extern "C" ARM void func_ov031_02228388(void) {
    int v = GetField16_02222e0c();
    switch (v) {
    case 0:
        func_ov031_02236878(7);
        SetField_022274c0_022274c0((int)func_ov031_02227ce4);
        break;
    case 1:
        func_ov031_02236878(6);
        func_ov031_0222855c();
        SetField_022274c0_022274c0((int)RegisterCallback_022283d8);
        break;
    }
}
