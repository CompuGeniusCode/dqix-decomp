#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
unsigned int GetField8Low4_02227558(void);
void SetField1014_022274d0(int a, int b);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_02228024(void);
extern "C" void func_ov031_02232508(void);

// USA: func_ov031_02227fb0  (semantic: CheckLow4ThenDispatchOrInit_02227fb0)
extern "C" ARM void func_ov031_02227fb0(void) {
    if (func_ov031_0223c054(1)) return;
    if (func_ov031_0223c054(0)) return;
    unsigned int low4 = GetField8Low4_02227558();
    switch (low4) {
    case 0:
        SetField1014_022274d0(0, 1);
        SetField_022274c0_022274c0((int)func_ov031_02228024);
        break;
    case 1:
        SetField1014_022274d0(1, 1);
        SetField_022274c0_022274c0((int)func_ov031_02232508);
        break;
    }
}
