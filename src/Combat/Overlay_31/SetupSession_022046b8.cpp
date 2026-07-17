#include <globaldefs.h>

void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void ZeroField164_02203250(void);
void UpdateObjFromContext_022031bc(int, int, int);
extern "C" void func_ov031_0220419c(void);
extern "C" int func_ov031_02204368(int);

// USA: func_ov031_022046b8
ARM int SetupSession_022046b8(void) {
	InitSessionFields_0220321c();
	ResetSessionState02203190();
	UpdateObjFromContext_022031bc(0x44, 0x43, 0x43 - 0x44);
	int result;
	int i = 0;
	do {
		func_ov031_0220419c();
		result = func_ov031_02204368(i);
		if (result == 1) break;
		i++;
	} while (i < 4);
	ZeroField164_02203250();
	return result == 1 ? 1 : 0;
}
