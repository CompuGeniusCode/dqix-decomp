#include <globaldefs.h>
void SetField18_02222e98(void);
extern "C" void func_ov031_0223c278(int);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228f9c(void);
// USA: func_ov031_02228f7c
ARM void SetField18AndAdvance_02228f7c(void) {
	SetField18_02222e98();
	func_ov031_0223c278(8);
	SetField_022274c0_022274c0((int)func_ov031_02228f9c);
}
