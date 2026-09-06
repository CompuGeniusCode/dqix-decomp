#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM int TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022317a8(void);

struct Struct02231744 { unsigned char flag; };
extern Struct02231744 data_ov031_02290cb0;

// USA: func_ov031_02231744
ARM void RegisterCallback_02231744(void) {
    if (func_ov031_0223c054(1) != 0) {
        return;
    }
    TailCall_02222ddc();
    if (data_ov031_02290cb0.flag == 0) {
        func_ov031_0223c078(3, 1, 1, 8);
    }
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetField_022274c0_022274c0((int)func_ov031_022317a8);
}
