#include <globaldefs.h>

struct GlobalPtrStruct02210314 {
	char pad[0xa0c];
	int fieldA0c;
};

extern GlobalPtrStruct02210314* data_ov031_0224e588;

// USA: func_ov031_02210314
ARM void SetGlobal0224e588FieldA0c_02210314(int v) {
	GlobalPtrStruct02210314* p = data_ov031_0224e588;
	if (p != NULL) {
		p->fieldA0c = v;
	}
}
