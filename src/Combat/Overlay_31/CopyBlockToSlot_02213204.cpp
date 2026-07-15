#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" void func_020ca408(void*, void*, int);

// USA: func_ov031_02213204
ARM void CopyBlockToSlot_02213204(int slot, void *src) {
	char *p = func_ov031_022133f8(0x10);
	func_020ca408(src, p + (slot << 8), 0xf0);
}
