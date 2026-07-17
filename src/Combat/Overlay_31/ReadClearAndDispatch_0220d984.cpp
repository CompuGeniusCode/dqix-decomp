#include <globaldefs.h>

void DispatchEvent_0220d9c8(short a, short b, int c, int d, int e);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220d984
ARM void ReadClearAndDispatch_0220d984(short a, int b, int c, int d) {
	char* base = (char*)data_ov031_0224e53c;
	short oldVal = *(short*)(base + 0x2280);
	*(short*)(base + 0x2280) = 0;
	DispatchEvent_0220d9c8(oldVal, a, b, c, d);
}
