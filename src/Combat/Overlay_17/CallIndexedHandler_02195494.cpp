#include <globaldefs.h>

extern "C" void func_ov017_02195214(int val, void* ptr);

// USA: func_ov017_02195494
ARM void CallIndexedHandler_02195494(void* obj, int index, int val) {
	int idx = index - 1;
	if (idx < 0 || idx > 2) return;
	void* ptr = (char*)obj + 0x42f1 + idx * 15;
	func_ov017_02195214(val, ptr);
}
