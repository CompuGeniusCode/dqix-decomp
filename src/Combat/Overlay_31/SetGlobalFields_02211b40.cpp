#include <globaldefs.h>

struct GlobalStruct0224e5ac {
	void* field0;
	void* field4;
};

extern GlobalStruct0224e5ac data_ov031_0224e5ac;

// USA: func_ov031_02211b40
ARM void SetGlobalFields_02211b40(void* a, void* b) {
	data_ov031_0224e5ac.field4 = a;
	data_ov031_0224e5ac.field0 = b;
}
