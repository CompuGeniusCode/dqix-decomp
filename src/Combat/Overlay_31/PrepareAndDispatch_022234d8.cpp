#include <globaldefs.h>

typedef void (*FnPtr022234d8)(void*, int, int);

extern void* SetupBuffer_02223478(const unsigned char*);
extern "C" void* func_ov031_0223b61c(void*, int*, int);
extern void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void func_ov031_0223b710(void*);

// USA: func_ov031_022234d8
ARM void PrepareAndDispatch_022234d8(const unsigned char* name, FnPtr022234d8 fn) {
	void* buf = SetupBuffer_02223478(name);
	int local;
	void* p = func_ov031_0223b61c(buf, &local, 4);
	CleanInvalidateCacheRange(p, (unsigned int)local);
	fn(p, 0, local);
	func_ov031_0223b710(p);
}
