#include <globaldefs.h>
extern "C" void func_ov031_02229a0c(void);
extern "C" void func_ov031_022235a0(int);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229a74(void);
// USA: func_ov031_022299ec
ARM void Setup1fAndAdvance_022299ec(void) {
	func_ov031_02229a0c();
	func_ov031_022235a0(0x1f);
	SetField_022274c0_022274c0((int)func_ov031_02229a74);
}
