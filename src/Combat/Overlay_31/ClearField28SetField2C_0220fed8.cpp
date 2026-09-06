#include <globaldefs.h>

extern void* data_ov031_0224e580;
void SetGlobal0224e588FieldA0c_02210314(int v);

// USA: func_ov031_0220fed8
ARM void ClearField28SetField2C_0220fed8(void) {
	if (data_ov031_0224e580 == NULL) return;
	SetGlobal0224e588FieldA0c_02210314(0);
	*(int*)((char*)data_ov031_0224e580 + 0x28) = 0;
	*(int*)((char*)data_ov031_0224e580 + 0x2c) = 1;
}
