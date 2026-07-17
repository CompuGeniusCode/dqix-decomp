#include <globaldefs.h>

extern "C" int func_020ca3b8(int, int, int);
void TailCallField4_0223e2c0(int, int);

struct Struct0223508c { unsigned char pad[4]; int field4; };
extern struct Struct0223508c data_ov031_02290ce8;

// USA: func_ov031_0223508c
ARM void InvalidateAndNotify_0223508c(int v) {
	func_020ca3b8(data_ov031_02290ce8.field4, 0x5000000, 0x200);
	TailCallField4_0223e2c0(1, v);
}
