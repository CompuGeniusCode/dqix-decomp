#include <globaldefs.h>

extern int GetData02104304Field4();
extern "C" void func_02030110(int a);
extern "C" void func_020301c8(int a, int b);
extern "C" void func_ov003_02168324(void* obj);

// USA: func_ov003_0216adbc
ARM void MaybeReset0216adbc(void* obj) {
	if (*(unsigned char*)((char*)obj + 0x5a4) != 0) return;
	int v = GetData02104304Field4();
	func_02030110(v);
	func_020301c8(v, *(int*)((char*)obj + 0x4e0));
	*(int*)((char*)obj + 0x4e0) = -1;
	func_ov003_02168324(obj);
	*(unsigned char*)((char*)obj + 0x4ec) = 6;
	*(unsigned char*)((char*)obj + 0x4e8) = 0;
}
