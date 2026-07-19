#include <globaldefs.h>

extern int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022339a8(void);
extern void SetField_022274c0_022274c0(int);
extern void RegisterCallback_02233700(void);
extern unsigned char data_ov031_02290cc8[3];

// USA: func_ov031_022336ac
extern "C" ARM void func_ov031_022336ac(void) {
	int field = GetField16_02222e0c();
	switch (field) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1:
		func_ov031_02236878(6);
		func_ov031_022339a8();
		data_ov031_02290cc8[2] = 1;
		break;
	default:
		return;
	}
	SetField_022274c0_022274c0((int)RegisterCallback_02233700);
}
