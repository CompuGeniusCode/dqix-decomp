#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" int func_ov031_02236878(int index);
ARM void RegisterCallback_02234770(void);
void SetField_022274c0_022274c0(int);

struct Struct02290ce0 { unsigned char flag; };
extern Struct02290ce0 data_ov031_02290ce0;

// USA: func_ov031_02234720
ARM void DispatchFieldTransition_02234720(void) {
    int v = GetField16_02222e0c();
    switch (v) {
        case 0:
            func_ov031_02236878(7);
            break;
        case 1:
            func_ov031_02236878(6);
            data_ov031_02290ce0.flag = 1;
            break;
        default:
            return;
    }
    SetField_022274c0_022274c0((int)RegisterCallback_02234770);
}
