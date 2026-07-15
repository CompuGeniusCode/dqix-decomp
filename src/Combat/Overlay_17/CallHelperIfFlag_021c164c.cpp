#include <globaldefs.h>

extern int data_ov017_021d8478;
extern "C" void func_ov003_02154f80(void);

// USA: func_ov017_021c164c
ARM void CallHelperIfFlag_021c164c(void) {
	if (data_ov017_021d8478 != 0) {
		func_ov003_02154f80();
	}
}
