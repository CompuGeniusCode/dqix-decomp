#include <globaldefs.h>

void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void ZeroField164_02203250(void);
void UpdateObjFromContext_022031bc(int a, unsigned short b, unsigned int c);
extern "C" int func_ov031_0220419c(void);
extern "C" int func_ov031_02204368(int a, int index);

// USA: func_ov031_022046b8
extern "C" ARM int func_ov031_022046b8(void) {
	InitSessionFields_0220321c();
	ResetSessionState02203190();
	UpdateObjFromContext_022031bc(0x44, 0x43, (unsigned int)-1);
	int result;
	int i = 0;
	do {
		int v = func_ov031_0220419c();
		result = func_ov031_02204368(v, i);
		if (result == 1) {
			break;
		}
		i++;
	} while (i < 4);
	ZeroField164_02203250();
	return result == 1;
}
