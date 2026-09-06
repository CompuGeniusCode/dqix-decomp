#include <globaldefs.h>

extern "C" void func_ov031_0222e404(void);
extern "C" void func_ov031_0222e484(void);
extern "C" void func_ov031_0222e7f8(void);
void SetField_022274c0_022274c0(int v);

// USA: func_ov031_0222e3e8
ARM void InitAndSetHandlerC_0222e3e8(void) {
    func_ov031_0222e404();
    func_ov031_0222e484();
    SetField_022274c0_022274c0((int)func_ov031_0222e7f8);
}
