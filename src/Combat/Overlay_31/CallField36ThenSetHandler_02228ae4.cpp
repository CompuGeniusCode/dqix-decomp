#include <globaldefs.h>

int GetField16_02222e0c(void);
void TailCallOffset94_02236878(int);
void SetField_022274c0_022274c0(int v);
void RegisterCallback_02228b0c(void);

// USA: func_ov031_02228ae4
ARM void CallField36ThenSetHandler_02228ae4(void) {
	if (GetField16_02222e0c() != 0) return;
	TailCallOffset94_02236878(6);
	SetField_022274c0_022274c0((int)RegisterCallback_02228b0c);
}
