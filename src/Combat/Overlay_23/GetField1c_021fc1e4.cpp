#include <globaldefs.h>

struct S021fc1e4 { char pad[0x1c]; int field1c; };

// USA: func_ov023_021fc1e4
ARM int GetField1c_021fc1e4(struct S021fc1e4 *obj) {
	return obj->field1c;
}
