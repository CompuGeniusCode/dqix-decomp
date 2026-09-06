#include <globaldefs.h>

extern "C" int func_ov031_02206ce8(void* g);
int IsEligibleForList_022068cc(void* obj);
extern "C" int func_ov031_02206900(void* a);
void DrainList0224e230_02206c08(void);
int MarkContextReadyIfInactive_022004d4(void);
void SetGlobal0224e540Field28_0220f0e4(int v);

extern void* data_ov031_0224e1cc;

// USA: func_ov031_02206d90  (semantic: ProcessPendingItemOrActivate_02206d90)
extern "C" ARM int func_ov031_02206d90(void) {
	int result;
	void* g = data_ov031_0224e1cc;
	if (g) {
		result = func_ov031_02206ce8(g);
		if (result == 0) {
			func_ov031_02206900(data_ov031_0224e1cc);
			if (IsEligibleForList_022068cc(data_ov031_0224e1cc) != 0) {
				data_ov031_0224e1cc = 0;
			}
			result = -26;
		}
		DrainList0224e230_02206c08();
	} else {
		if (MarkContextReadyIfInactive_022004d4() == 0) {
			result = -26;
		} else {
			SetGlobal0224e540Field28_0220f0e4(0);
			result = 0;
		}
	}
	return result;
}
