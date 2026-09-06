#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02227b38(void);
extern "C" void func_ov031_02223568(int);
extern void SetField_022274c0_022274c0(int);
extern void RegisterCallbackIfField16Active_02231d48(void);

// USA: func_ov031_02231d08
extern "C" ARM void func_ov031_02231d08(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	if (func_ov031_0223c054(0) != 0) {
		return;
	}
	func_ov031_02227b38();
	func_ov031_02223568(1);
	SetField_022274c0_022274c0((int)RegisterCallbackIfField16Active_02231d48);
}
