#include <globaldefs.h>

struct Obj021f79ec { char pad[0xc]; unsigned char flags; char pad2[3]; void* field10; char pad3[0x1c - 0x14]; int field1c; };

// USA: func_ov023_021f79ec
ARM void SetFieldAndFlags3_021f79ec(struct Obj021f79ec* obj, void* v) {
	obj->field10 = v;
	obj->field1c = 0;
	obj->flags |= 3;
}
