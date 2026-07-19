#include <globaldefs.h>

extern signed char GetField1b_02237e9c(void);
extern void SetField_022274c0_022274c0(int v);
void DispatchFieldValueThenSetup_0222a890(void);

// USA: func_ov031_0222a86c  (semantic: SetHandlerIfField1bNotNegTwo_0222a86c)
extern "C" ARM void func_ov031_0222a86c(void) {
	if (GetField1b_02237e9c() == -2) return;
	SetField_022274c0_022274c0((int)DispatchFieldValueThenSetup_0222a890);
}
