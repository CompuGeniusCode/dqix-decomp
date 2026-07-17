#include <globaldefs.h>

extern void* data_ov031_0224e580;
int RegisterCallbackAndArm_0220fe44(int (*cb)(int*));
void ClearField28SetField2C_0220fed8(void);

// USA: func_ov031_0220f728
ARM void ArmThenPropagateField0c_0220f728(void) {
	if (RegisterCallbackAndArm_0220fe44(NULL)) {
		void* val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x24) = *(int*)(*(int**)((char*)val + 0xc));
		val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x20) = 1;
	}
	ClearField28SetField2C_0220fed8();
}
