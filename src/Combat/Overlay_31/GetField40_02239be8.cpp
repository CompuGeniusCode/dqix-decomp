#include <globaldefs.h>

struct Inner_02239be8 { unsigned char pad[0x40]; int field40; };
struct Outer_02239be8 { unsigned char pad[4]; struct Inner_02239be8* inner; };
extern struct Outer_02239be8 data_ov031_02290d18;

// USA: func_ov031_02239be8
ARM int GetField40_02239be8(void) {
	return data_ov031_02290d18.inner->field40;
}
