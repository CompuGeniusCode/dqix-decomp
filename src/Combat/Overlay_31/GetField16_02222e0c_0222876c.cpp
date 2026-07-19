#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022287d4(void);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
ARM void SetField18_02222e98(void);
extern "C" void func_ov031_02228910(void);
ARM void SetField_022274c0_022274c0(int);

// USA: func_ov031_0222876c  (semantic: DispatchByField16ThenSetHandler_0222876c)
extern "C" ARM void func_ov031_0222876c(void) {
	int f16 = GetField16_02222e0c();
	switch (f16) {
	case 0:
		func_ov031_02236878(7);
		SetField_022274c0_022274c0((int)func_ov031_022287d4);
		break;
	case 1:
		func_ov031_02236878(6);
		func_ov031_02237b2c(0x18, 0, 1, -1, 0);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_02228910);
		break;
	}
}
