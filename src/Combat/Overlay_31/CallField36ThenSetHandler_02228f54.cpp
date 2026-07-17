#include <globaldefs.h>

int GetField16_02222e0c(void);
void TailCallOffset94_02236878(int);
void SetField_022274c0_022274c0(int v);
void SetField18AndAdvance_02228f7c(void);

// USA: func_ov031_02228f54
ARM void CallField36ThenSetHandler_02228f54(void) {
	if (GetField16_02222e0c() != 0) return;
	TailCallOffset94_02236878(7);
	SetField_022274c0_022274c0((int)SetField18AndAdvance_02228f7c);
}
