#include <globaldefs.h>

extern "C" void func_020542b4(void* a, void* b, void* c);

// USA: func_ov017_021a1178
ARM void ComputeAndCall_021a1178(char* base, int x) {
	char* p0 = base + 0x2c8 + 0x1000 + x * 0x5ec;
	int x1 = x + 1;
	char* p1 = base + 0x38 + x1 * 0x14;
	char* p2 = base + 0x2cc + x1 * 0x70;
	func_020542b4(p0, p1, p2);
}
