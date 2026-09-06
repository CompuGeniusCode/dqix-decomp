#include <globaldefs.h>

struct GlobalPtrStruct022101ac {
	char pad[0x30];
	int field30;
};

extern GlobalPtrStruct022101ac* data_ov031_0224e588;

// USA: func_ov031_022101ac
ARM void SetGlobal0224e588Field30_022101ac(int v) {
	GlobalPtrStruct022101ac* p = data_ov031_0224e588;
	if (p != NULL) {
		p->field30 = v;
	}
}
