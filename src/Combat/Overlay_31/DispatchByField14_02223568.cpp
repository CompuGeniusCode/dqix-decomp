#include <globaldefs.h>

extern void GetFields1014_022274e4(int* a, int* b);
extern "C" void func_ov031_02222ce4(void*);

#pragma optimize_for_size off
// USA: func_ov031_02223568
ARM void DispatchByField14_02223568(void* arg) {
	int val;
	GetFields1014_022274e4(0, &val);
	if (val != 1) return;
	func_ov031_02222ce4(arg);
}
