#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int, void*);
extern "C" void func_ov031_0223ba20(void*);
extern "C" void func_ov031_0223cf70(void*);
extern void* data_ov031_02250ba8;

// USA: func_ov031_022231f0
ARM void CleanupLoop_022231f0(void* orig) {
	func_ov031_0223e2c0(0, orig);
	void* f10 = *(void**)((char*)data_ov031_02250ba8 + 0x10);
	if (f10 != 0) {
		func_ov031_0223e2c0(0, f10);
	}
	int i = 0;
	do {
		void* elem = ((void**)data_ov031_02250ba8)[i];
		if (elem != 0) func_ov031_0223ba20(elem);
		i++;
	} while (i < 2);
	void* f8 = *(void**)((char*)data_ov031_02250ba8 + 8);
	func_ov031_0223ba20(f8);
	func_ov031_0223cf70(&data_ov031_02250ba8);
}
