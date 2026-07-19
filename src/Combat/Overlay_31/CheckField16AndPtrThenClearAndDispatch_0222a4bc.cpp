#include <globaldefs.h>

extern int GetField16_02222e0c(void);
extern int IsPtr02290c44Null_02227840(void);
extern void ClearField18_02222e80(void);
extern void SetField_022274c0_022274c0(int);
extern void RunThreeSteps_0222a4f0(void);

// USA: func_ov031_0222a4bc  (semantic: CheckField16AndPtrThenClearAndDispatch_0222a4bc)
extern "C" ARM void func_ov031_0222a4bc(void) {
	if (GetField16_02222e0c() == -2) return;
	if (IsPtr02290c44Null_02227840() == 0) return;
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_0222a4f0);
}
