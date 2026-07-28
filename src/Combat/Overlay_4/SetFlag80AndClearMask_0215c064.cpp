#include <globaldefs.h>

extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);

// USA: func_ov004_0215c064  (semantic: SetFlag80AndClearMask_0215c064)
extern "C" ARM int func_ov004_0215c064(void* obj) {
	func_ov011_021848a0(obj, 0x50);
	func_ov023_021f65d4(obj, 2, 8);
	return 0;
}
