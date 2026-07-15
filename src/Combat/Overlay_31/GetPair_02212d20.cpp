#include <globaldefs.h>

extern "C" void func_ov031_0221c3f8(void *buf);

// USA: func_ov031_02212d20
ARM long long GetPair_02212d20(void) {
	char buf[0x14];
	func_ov031_0221c3f8(buf);
	return *(long long*)buf;
}
