#include <globaldefs.h>

extern "C" void (* volatile data_ov031_02290fc8)(void*);

struct Obj02241720 {
	char pad800[0x800];
	void* field800;
};

// USA: func_ov031_02241720
extern "C" ARM void func_ov031_02241720(Obj02241720* obj) {
	if (!obj) return;
	if (obj->field800)
		data_ov031_02290fc8(obj->field800);
	data_ov031_02290fc8(obj);
}
