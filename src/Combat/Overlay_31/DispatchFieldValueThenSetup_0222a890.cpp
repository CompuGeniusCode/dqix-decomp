#include <globaldefs.h>

extern "C" void func_ov031_0222a900(void);
extern "C" void func_ov031_0222a904(void);
extern signed char GetField1b_02237e9c(void);
extern unsigned char data_ov031_02290c78;
extern "C" void func_ov031_02236878(int);
extern void SetOffset1e298_0222785c(int);
extern "C" void func_ov031_02237e58(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a908(void);

// USA: func_ov031_0222a890
ARM void DispatchFieldValueThenSetup_0222a890(void) {
	func_ov031_0222a900();
	func_ov031_0222a904();
	signed char v = GetField1b_02237e9c();
	switch (v) {
	case 0:
		(&data_ov031_02290c78)[1] = 0;
		func_ov031_02236878(7);
		break;
	case 1:
		(&data_ov031_02290c78)[1] = 1;
		func_ov031_02236878(0xe);
		break;
	default:
		return;
	}
	SetOffset1e298_0222785c(0);
	func_ov031_02237e58();
	SetField_022274c0_022274c0((int)func_ov031_0222a908);
}
