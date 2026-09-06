#include <globaldefs.h>

extern "C" int func_020c7e0c(void* data, void* structPtr, int flag);
void CallGlobalWithArg_02205174(int v);

struct Struct022051a8 { unsigned char pad[0xd]; signed char flagsByte; };

// USA: func_ov031_022051a8  (semantic: ProcessAndMaybeNotify_022051a8)
extern "C" ARM int func_ov031_022051a8(void* a, struct Struct022051a8* b) {
	int flag = (b == NULL || (b->flagsByte & 1) != 0) ? 1 : 0;
	int r = func_020c7e0c(a, b, flag);
	if (r == 0) {
		CallGlobalWithArg_02205174((int)b);
	}
	return (r != 0) ? 0 : -42;
}
