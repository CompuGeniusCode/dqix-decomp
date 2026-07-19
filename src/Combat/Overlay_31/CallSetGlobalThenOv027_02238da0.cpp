#include <globaldefs.h>

void SetGlobal02290d14_02239108(unsigned short v);
extern "C" void func_ov027_021dcd20(void);

// USA: func_ov031_02238da0
ARM void CallSetGlobalThenOv027_02238da0(void) {
	SetGlobal02290d14_02239108(6);
	func_ov027_021dcd20();
}
