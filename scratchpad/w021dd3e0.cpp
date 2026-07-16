#include <globaldefs.h>

struct Struct021dd3e0 {
	char pad[0x4];
	int field_0x4;
};

// USA: func_ov027_021dd3e0
int IsFlagBit0Set021dd3e0(struct Struct021dd3e0* obj) {
	return (obj->field_0x4 & 1) != 0;
}
