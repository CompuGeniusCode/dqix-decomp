#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov027_021dd3b0();
extern "C" void func_ov027_021dd3f8(void *a, int b, int c, int d);

struct RootStruct021dd55c {
	void *field0;
};

extern struct RootStruct021dd55c data_ov027_021e3420;

// USA: func_ov027_021dd55c
ARM void UpdateEntryFlag_021dd55c(int value) {
	int state = DisableIRQInterrupts();
	int r = func_ov027_021dd3b0();
	if (r != 0) {
		func_ov027_021dd3f8((char *)data_ov027_021e3420.field0 + 0xc4, 0, value, 0);
	}
	SetIRQInterruptState(state);
}
