#include <globaldefs.h>

struct Inner_02239bd4 { unsigned char pad[0x52]; unsigned short field52; };
struct Outer_02239bd4 { unsigned char pad[4]; struct Inner_02239bd4* inner; };
extern struct Outer_02239bd4 data_ov031_02290d18;

// USA: func_ov031_02239bd4
ARM unsigned short GetField52_02239bd4(void) {
	return data_ov031_02290d18.inner->field52;
}
