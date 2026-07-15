#include <globaldefs.h>

extern "C" void func_ov031_022289a4(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_022364c0(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228a24(void);

// USA: func_ov031_02228980
ARM void RunThreeStagesThenSetField_02228980(void) {
    func_ov031_022289a4();
    func_ov031_022235a0(0x19);
    func_ov031_022364c0();
    SetField_022274c0_022274c0((int)func_ov031_02228a24);
}
