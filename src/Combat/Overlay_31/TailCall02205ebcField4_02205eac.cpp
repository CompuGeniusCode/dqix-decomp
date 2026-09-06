#include <globaldefs.h>

extern "C" int func_ov031_02205ebc(int a);

struct Obj02205eac {
	char pad[0x4];
	int field4;
};

// USA: func_ov031_02205eac
ARM int TailCall02205ebcField4_02205eac(Obj02205eac* obj) {
	return func_ov031_02205ebc(obj->field4);
}
