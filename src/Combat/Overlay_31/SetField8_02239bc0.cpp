#include <globaldefs.h>

struct Inner_02239bc0 { unsigned char pad[8]; int field8; };
struct Outer_02239bc0 { unsigned char pad[4]; struct Inner_02239bc0* inner; };
extern struct Outer_02239bc0 data_ov031_02290d18;

// USA: func_ov031_02239bc0
ARM void SetField8_02239bc0(int v) {
	data_ov031_02290d18.inner->field8 = v;
}
