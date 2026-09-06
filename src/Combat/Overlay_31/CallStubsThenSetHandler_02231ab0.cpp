#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02231aec(void);

// USA: func_ov031_02231ab0  (semantic: CallStubsThenSetHandler_02231ab0)
extern "C" ARM void func_ov031_02231ab0(void) {
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_02231aec);
}
