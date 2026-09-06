#include <globaldefs.h>

struct Inner_0223a274 { unsigned char pad[0x4c]; int field4c; };
struct Outer_0223a274 { unsigned char pad[4]; struct Inner_0223a274* inner; };
extern struct Outer_0223a274 data_ov031_02290d18;

// USA: func_ov031_0223a274
ARM void SetField4c_0223a274(int v) {
	data_ov031_02290d18.inner->field4c = v;
}
