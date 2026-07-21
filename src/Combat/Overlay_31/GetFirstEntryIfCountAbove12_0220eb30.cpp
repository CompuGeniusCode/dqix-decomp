#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

struct Table0220eb30 { char pad[0x270]; int* field270; unsigned int field274; };

// USA: func_ov031_0220eb30  (semantic: GetFirstEntryIfCountAbove12_0220eb30)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0220eb30(void) {
	int state = DisableIRQInterrupts();
	int base = GetData0224e53c_0220d60c();
	int result = 0;
	if (base == 0) {
		SetIRQInterruptState(state);
		return result;
	}
	struct Table0220eb30* t = (struct Table0220eb30*)(base + 0x2000);
	if (t->field270 != NULL) {
		if (t->field274 > 0xc) {
			result = *t->field270;
		}
	}
	SetIRQInterruptState(state);
	return result;
}
