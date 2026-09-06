#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void *self, int flags, int a, int b);
extern "C" void func_ov012_02189fb0(void *self, void *ptr, int c);
extern "C" void func_0205d304(void *a, void *b, int c, int d, int e, int f, int g, int h);

// USA: func_ov012_02189f38
ARM void BuildMessageD_02189f38(char *self) {
	func_ov012_021893b4(self, *(unsigned char *)(self + 0x1371), 0x19, 0xa);
	void *ptr = *(void **)(self + 0x1374);
	memset(ptr, 0, 0x960);
	func_ov012_02189fb0(self, *(void **)(self + 0x1374), 0);
	func_0205d304(self + 0xac, *(void **)(self + 0x1374), 0, 1, 0, 1, 0, 0);
}
