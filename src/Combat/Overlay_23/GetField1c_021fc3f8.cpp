#include <globaldefs.h>

struct S021fc3f8 { char pad[0x1c]; int field1c; };

// USA: func_ov023_021fc3f8
ARM int GetField1c_021fc3f8(struct S021fc3f8 *obj) {
	return obj->field1c;
}
