#include <globaldefs.h>

extern "C" int func_ov031_0221bfe8(void*);
extern "C" int func_ov031_0221aed8(void*, int);

// USA: func_ov031_0221c1c4  (semantic: CheckInitAndApply_0221c1c4)
#pragma optimize_for_size off
extern "C" ARM bool func_ov031_0221c1c4(int x) {
	char buf[0x14];
	if (func_ov031_0221bfe8(buf) == 0) return false;
	return func_ov031_0221aed8(buf, x) != 0;
}
