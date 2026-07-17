#include <globaldefs.h>

struct GlobalStruct0224e5c4_022133f8 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	unsigned int fieldc;
	unsigned int field10;
};

extern GlobalStruct0224e5c4_022133f8 data_ov031_0224e5c4;

// USA: func_ov031_022133f8
ARM void* GetFieldPtrByMask_022133f8(unsigned int mask) {
	if (mask & 1) return (void*)data_ov031_0224e5c4.fieldc;
	if (mask & 2) return (void*)data_ov031_0224e5c4.field0;
	if (mask & 4) return (void*)data_ov031_0224e5c4.field4;
	if (mask & 8) return (void*)data_ov031_0224e5c4.field8;
	if (mask & 0x10) return (void*)data_ov031_0224e5c4.field10;
	return NULL;
}
