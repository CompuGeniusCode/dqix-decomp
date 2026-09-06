#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
extern int data_02109bf4;

// USA: func_ov001_02163640
ARM int SetStateFromModeOrDefault_02163640(void* param, int mode) {
	int val = -1;
	if (mode == 2) {
		int id = func_ov017_021d60f4(param);
		val = func_ov017_021d60f4((char*)param + 8);
	} else if (mode == 1) {
		val = func_ov017_021d60f4(param);
	}
	if (val < 0) {
		return 0;
	}
	SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, val);
	DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0);
	return 1;
}
