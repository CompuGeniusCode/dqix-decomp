#include <globaldefs.h>

int IsNotInList0224e22c_02207180(void* v);
int IsInList0224e230_022071b4(void* item);

#pragma optimize_for_size off
// USA: func_ov031_022068cc
ARM int IsEligibleForList_022068cc(void* obj) {
	if ((int)obj >= 0) {
		if (IsNotInList0224e22c_02207180(obj) != 0) {
			if (IsInList0224e230_022071b4(obj) == 0) {
				return 1;
			}
		}
	}
	return 0;
}
