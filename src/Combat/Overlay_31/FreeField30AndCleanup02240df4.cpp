#include <globaldefs.h>

extern "C" void (*data_ov031_02290fc8)(void*);
extern "C" void func_ov031_02240e70(void*);

struct Obj02240df4 {
	char pad[0x30];
	void* field30;
};

// USA: func_ov031_02240df4
ARM void FreeField30AndCleanup02240df4(struct Obj02240df4* obj) {
	data_ov031_02290fc8(obj->field30);
	func_ov031_02240e70(obj);
}
