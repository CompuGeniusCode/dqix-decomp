#include <globaldefs.h>

extern void GetFields1014_022274e4(int* a, int* b);
extern "C" void func_ov031_0223690c(void*);
extern "C" void func_ov031_02236ea0(void*);

#pragma optimize_for_size off
// USA: func_ov031_02223518
ARM void DispatchByField10_02223518(void* arg) {
	int val;
	GetFields1014_022274e4(&val, 0);
	if (val == 1) {
		func_ov031_0223690c(arg);
		return;
	}
	if (val != 2) return;
	func_ov031_02236ea0(arg);
}
