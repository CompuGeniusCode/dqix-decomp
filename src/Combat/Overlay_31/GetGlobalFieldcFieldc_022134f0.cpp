#include <globaldefs.h>

struct GlobalStruct0224e5c4_022134f0 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	void* fieldc;
};

extern GlobalStruct0224e5c4_022134f0 data_ov031_0224e5c4;

// USA: func_ov031_022134f0
ARM void* GetGlobalFieldcFieldc_022134f0(void) {
	return *(void**)((char*)data_ov031_0224e5c4.fieldc + 0xc);
}
