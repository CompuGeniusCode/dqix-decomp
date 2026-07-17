#include <globaldefs.h>

int IsGlobal02290d10Set_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallback_02231df8(void);

// USA: func_ov031_02232004
ARM void RegisterCallbackIfNot_02232004(void) {
	if (IsGlobal02290d10Set_02237eb0() != 0) {
		return;
	}
	SetField_022274c0_022274c0((int)RegisterCallback_02231df8);
}
