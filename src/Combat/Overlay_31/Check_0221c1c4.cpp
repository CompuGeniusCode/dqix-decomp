#include <globaldefs.h>

extern "C" int func_ov031_0221bfe8(void*);
extern "C" int func_ov031_0221aed8(void*, int);

// USA: func_ov031_0221c1c4
#pragma optimize_for_size off
ARM int Check_0221c1c4(int a) {
	char buf[0x14];
	int r;
	if (func_ov031_0221bfe8(buf) == 0) {
		r = 0;
	} else {
		r = func_ov031_0221aed8(buf, a) != 0;
	}
	return r;
}
