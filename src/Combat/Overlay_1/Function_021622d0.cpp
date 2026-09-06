#include <globaldefs.h>

extern "C" void* func_02012fe4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov001_021622d0
ARM int Function_021622d0(void* obj) {
	int v = *(int*)((char*)func_02012fe4(obj) + 0x424);
	func_ov017_021d6134(obj, v);
	return 1;
}
