#include <globaldefs.h>
#include "System/Memory.h"

ARM int GetGlobal02290cfc_02236474(void);
extern "C" int func_ov031_022130ac(void);
extern "C" void* func_ov031_0221b9a4(void);
extern "C" void func_ov031_02222bdc(void);
ARM void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" void func_ov031_0223cbbc(int, int);
ARM void SetField1014_022274d0(int a, int b);
ARM void SetField_022274c0_022274c0(int);
void InitAndSetHandlerC_0222e3e8(void);
void ClearFlagAndSetupTag45_02233e4c(void);

struct Struct02233ce0 {
    unsigned char flag0;
    unsigned char pad[3];
    int field4;
};
extern Struct02233ce0 data_ov031_02290cd0;

// USA: func_ov031_02233ce0
ARM void RegisterAndInit_02233ce0(void) {
    char* g = (char*)GetGlobal02290cfc_02236474();
    if (data_ov031_02290cd0.field4 != 0) {
        if (func_ov031_022130ac() == 0) {
            return;
        }
    }
    VectorizedInvertedMemcpy(func_ov031_0221b9a4(), g + 0xf0, 0xe);
    VectorizedInvertedMemcpy(func_ov031_0221b9a4(), g + 0x1f0, 0xe);
    func_ov031_02222bdc();
    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_0223cbbc(0, 0x15);
    if (data_ov031_02290cd0.flag0 == 0) {
        SetField1014_022274d0(0, 1);
        SetField_022274c0_022274c0((int)InitAndSetHandlerC_0222e3e8);
    } else {
        SetField1014_022274d0(0, 1);
        SetField_022274c0_022274c0((int)ClearFlagAndSetupTag45_02233e4c);
    }
}
