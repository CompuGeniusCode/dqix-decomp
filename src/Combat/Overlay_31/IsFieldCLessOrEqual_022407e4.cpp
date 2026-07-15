#include <globaldefs.h>

struct Struct022407e4 { unsigned char pad[0xc]; unsigned int field_c; };

// USA: func_ov031_022407e4
ARM int IsFieldCLessOrEqual_022407e4(struct Struct022407e4* obj, unsigned int val) {
	return obj->field_c <= val;
}
