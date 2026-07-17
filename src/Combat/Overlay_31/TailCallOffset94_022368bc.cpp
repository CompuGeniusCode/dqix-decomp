#include <globaldefs.h>

extern "C" int func_020bc1cc(void*, int, int);
extern void* data_ov031_02290d00;

// USA: func_ov031_022368bc
ARM int TailCallOffset94_022368bc(int a0, int a1) {
	return func_020bc1cc((char*)data_ov031_02290d00 + 0x94, a0, a1);
}
