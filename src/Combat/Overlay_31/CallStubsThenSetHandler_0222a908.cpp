#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a964(void);

extern unsigned char data_ov031_02290c78;

// USA: func_ov031_0222a908  (semantic: CallStubsThenSetHandler_0222a908)
extern "C" ARM void func_ov031_0222a908(void) {
	if (func_ov031_02237eb0() != 0) return;
	if ((&data_ov031_02290c78)[1] == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_0222a964);
}
