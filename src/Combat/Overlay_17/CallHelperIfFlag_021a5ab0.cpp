#include <globaldefs.h>

extern int data_ov017_021d83ac;
extern "C" void func_ov002_0215b6c0(void);

// USA: func_ov017_021a5ab0
ARM void CallHelperIfFlag_021a5ab0(void) {
	if (data_ov017_021d83ac != 0) {
		func_ov002_0215b6c0();
	}
}
