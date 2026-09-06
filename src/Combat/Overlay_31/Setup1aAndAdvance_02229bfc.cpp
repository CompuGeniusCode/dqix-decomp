#include <globaldefs.h>
extern "C" void func_ov031_02229c1c(void);
extern "C" void func_ov031_022235a0(int);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229c84(void);
// USA: func_ov031_02229bfc
ARM void Setup1aAndAdvance_02229bfc(void) {
	func_ov031_02229c1c();
	func_ov031_022235a0(0x1a);
	SetField_022274c0_022274c0((int)func_ov031_02229c84);
}
