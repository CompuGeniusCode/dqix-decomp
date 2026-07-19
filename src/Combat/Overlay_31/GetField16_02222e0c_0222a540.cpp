#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" int func_ov031_02236878(int index);
ARM void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222a598(void);

struct GlobalStruct02290c74_0222a540 {
	unsigned char field0;
	unsigned char field1;
};

extern GlobalStruct02290c74_0222a540 data_ov031_02290c74;

// USA: func_ov031_0222a540  (semantic: SetActionModeByField16_0222a540)
extern "C" ARM void func_ov031_0222a540(void) {
	int f16 = GetField16_02222e0c();
	if (f16 != 0) {
		if (f16 != 1) return;
		data_ov031_02290c74.field1 = 1;
		func_ov031_02236878(6);
	} else {
		data_ov031_02290c74.field1 = 0;
		func_ov031_02236878(7);
	}
	SetField_022274c0_022274c0((int)func_ov031_0222a598);
}
