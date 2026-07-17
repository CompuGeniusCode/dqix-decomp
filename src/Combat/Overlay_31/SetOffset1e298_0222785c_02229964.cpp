#include <globaldefs.h>

extern unsigned char data_ov031_02290c68;

void InitAndDispatchFour_022364c0(void);
void CallFunc020bc548AtOffset94_022368e0(void);
void TailCallOffset94_02236878(int);
ARM void SetOffset1e298_0222785c(int v);
ARM void *RegisterCallback120_022277e4(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void ConfigureThenDispatch_022298a8(void);

// USA: func_ov031_02229964
ARM void DispatchByMode_02229964(int mode) {
	if (mode == 2) {
		InitAndDispatchFour_022364c0();
		data_ov031_02290c68 = 1;
		CallFunc020bc548AtOffset94_022368e0();
		TailCallOffset94_02236878(0x10);
	} else if (mode == 3) {
		data_ov031_02290c68 = 2;
		CallFunc020bc548AtOffset94_022368e0();
		TailCallOffset94_02236878(0x12);
	} else {
		data_ov031_02290c68 = 0;
		CallFunc020bc548AtOffset94_022368e0();
		TailCallOffset94_02236878(0x12);
	}
	SetOffset1e298_0222785c(0);
	RegisterCallback120_022277e4();
	SetField_022274c0_022274c0((int)ConfigureThenDispatch_022298a8);
}
