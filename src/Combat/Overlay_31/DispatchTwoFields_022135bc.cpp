#include <globaldefs.h>

struct GlobalStruct0224e5c4_022135bc {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	unsigned int fieldc;
	unsigned int field10;
};

extern GlobalStruct0224e5c4_022135bc data_ov031_0224e5c4;

void DispatchHandlerAndClearField_02213270(unsigned int mask, int a1, int a2);

// USA: func_ov031_022135bc
ARM void DispatchTwoFields_022135bc(void) {
	DispatchHandlerAndClearField_02213270(8, data_ov031_0224e5c4.field8, 0xc);
	DispatchHandlerAndClearField_02213270(0x10, data_ov031_0224e5c4.field10, 0xd18);
}
