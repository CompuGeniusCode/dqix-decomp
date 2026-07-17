#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov031_02206ce8(void);
extern "C" void func_ov031_02206900(void* obj);
int IsEligibleForList_022068cc(void* obj);
void DrainList0224e230_02206c08(void);
int MarkContextReadyIfInactive_022004d4(void);
void SetGlobal0224e540Field28_0220f0e4(int v);

extern void* data_ov031_0224e1cc;

// USA: func_ov031_02206d90
ARM int ProcessOrReset_02206d90(void) {
	int ret;
	if (data_ov031_0224e1cc != NULL) {
		int ce8 = func_ov031_02206ce8();
		if (ce8 != 0) {
			ret = ce8;
		} else {
			func_ov031_02206900(data_ov031_0224e1cc);
			if (IsEligibleForList_022068cc(data_ov031_0224e1cc) != 0) {
				data_ov031_0224e1cc = NULL;
			}
			ret = -26;
		}
		DrainList0224e230_02206c08();
	} else {
		if (MarkContextReadyIfInactive_022004d4() == 0) {
			ret = -26;
		} else {
			SetGlobal0224e540Field28_0220f0e4(0);
			ret = 0;
		}
	}
	return ret;
}
