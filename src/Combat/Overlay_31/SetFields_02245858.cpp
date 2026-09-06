#include <globaldefs.h>

struct Struct02245858 { unsigned char b0; unsigned char pad[0x13]; int field14; };
extern struct Struct02245858 data_ov031_02291f24;

// USA: func_ov031_02245858
ARM void SetFields_02245858(int a, char b) {
	data_ov031_02291f24.field14 = a;
	data_ov031_02291f24.b0 = b;
}
