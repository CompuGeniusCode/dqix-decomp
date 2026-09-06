#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern int TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228fec(void);

// USA: func_ov031_02228f9c  (semantic: CallStubsThenSetHandler_02228f9c)
extern "C" ARM void func_ov031_02228f9c(void) {
	if (func_ov031_0223c054(1) != 0) return;
	TailCall_02222ddc();
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_02228fec);
}
