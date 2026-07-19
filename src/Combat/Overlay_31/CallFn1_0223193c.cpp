#include <globaldefs.h>

extern signed char GetField1b_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
extern void SetField_022274c0_022274c0(int);
extern void RegisterCallbackIfNot_02231968(void);

// USA: func_ov031_0223193c  (semantic: CallFn1_0223193c)
extern "C" ARM void func_ov031_0223193c(void) {
	if (GetField1b_02237e9c() != 0) {
		return;
	}
	func_ov031_02236878(6);
	func_ov031_02237e58();
	SetField_022274c0_022274c0((int)RegisterCallbackIfNot_02231968);
}
