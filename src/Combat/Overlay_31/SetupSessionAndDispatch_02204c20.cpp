#include <globaldefs.h>

void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void ZeroField164_02203250(void);
void UpdateObjFromContext_022031bc(int, int, int);
extern "C" int func_ov031_022048a8(void*, int, int, int, int);

// USA: func_ov031_02204c20
#pragma optimize_for_size off
ARM int SetupSessionAndDispatch_02204c20(void* a, int count, int c) {
	if (count == 0) return -1;

	InitSessionFields_0220321c();
	ResetSessionState02203190();
	UpdateObjFromContext_022031bc(0, 0x35, count);

	int result = func_ov031_022048a8(a, 1, c, 0, 0);
	ZeroField164_02203250();
	return result;
}
