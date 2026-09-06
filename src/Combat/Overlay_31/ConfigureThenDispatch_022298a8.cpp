#include <globaldefs.h>

extern "C" void func_ov031_022364c0(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern void SetOffset1e298_0222785c(int);
void *RegisterCallback120_022277e4(void);
void SetField_022274c0_022274c0(int v);
ARM void ConfigureThenDispatch_022298a8(void);
extern unsigned char data_ov031_02290c68;

// USA: func_ov031_02229964
extern "C" ARM void func_ov031_02229964(int mode) {
	if (mode == 2) {
		func_ov031_022364c0();
		data_ov031_02290c68 = 1;
		func_ov031_022368e0();
		func_ov031_02236878(0x10);
	} else if (mode == 3) {
		data_ov031_02290c68 = 2;
		func_ov031_022368e0();
		func_ov031_02236878(0x12);
	} else {
		data_ov031_02290c68 = 0;
		func_ov031_022368e0();
		func_ov031_02236878(0x12);
	}
	SetOffset1e298_0222785c(0);
	RegisterCallback120_022277e4();
	SetField_022274c0_022274c0((int)ConfigureThenDispatch_022298a8);
}
