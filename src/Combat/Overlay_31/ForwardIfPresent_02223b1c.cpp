#include <globaldefs.h>

extern int TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223da58(void*);
extern "C" void func_ov031_0223cf70(void*);
extern void* data_ov031_02250bf8;

#pragma optimize_for_size off
// USA: func_ov031_02223b1c
ARM void ForwardIfPresent_02223b1c() {
	void* g = data_ov031_02250bf8;
	if (g == 0) return;
	void* f4 = *(void**)((char*)g + 4);
	TailCallForward_0223e2e0(0, f4);
	void* g2 = data_ov031_02250bf8;
	void* f0 = *(void**)g2;
	func_ov031_0223da58(f0);
	func_ov031_0223cf70(&data_ov031_02250bf8);
}
