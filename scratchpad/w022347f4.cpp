#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
ARM int IsField19ZeroOrNull_02222e54(void);
ARM void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
ARM void SetField1014_022274d0(int a, int b);
ARM void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_02232508(void);
extern "C" void func_ov031_022348cc(void);

struct Struct022347f4_02290ce0 { unsigned char flag; };
extern Struct022347f4_02290ce0 data_ov031_02290ce0;

// USA: func_ov031_022347f4
extern "C" ARM void func_ov031_022347f4(void) {
    if (func_ov031_0223c054(0) != 0) return;
    if (data_ov031_02290ce0.flag == 0) {
        if (func_ov031_0223c054(1) != 0) return;
    }
    if (IsField19ZeroOrNull_02222e54() == 0) return;
    TailCallElemAtIndex30_0223c7c4(0);
    if (data_ov031_02290ce0.flag == 0) {
        func_ov031_02223440();
        func_ov031_0223cbbc(1, 1);
    }
    func_ov031_0223cbbc(0, 0x15);
    if (data_ov031_02290ce0.flag == 0) {
        SetField1014_022274d0(2, 1);
        SetField_022274c0_022274c0((int)func_ov031_02232508);
    } else {
        SetField1014_022274d0(2, 1);
        SetField_022274c0_022274c0((int)func_ov031_022348cc);
    }
}
