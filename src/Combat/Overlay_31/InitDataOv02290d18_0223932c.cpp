#include <globaldefs.h>

struct DataOv02290d18 { void* unk0; void* field4; };
extern struct DataOv02290d18 data_ov031_02290d18;

// USA: func_ov031_0223932c  (semantic: InitDataOv02290d18_0223932c)
extern "C" ARM void func_ov031_0223932c(void* obj) {
	data_ov031_02290d18.field4 = obj;
	*(int*)((char*)obj + 0x40) = 0;
	*(int*)((char*)data_ov031_02290d18.field4 + 0x1000 + 0x3a8) = 0;
	*(int*)((char*)data_ov031_02290d18.field4 + 0x1000 + 0x3ac) = 0;
	*(int*)((char*)data_ov031_02290d18.field4 + 0x1000 + 0x3b0) = 0;
}
