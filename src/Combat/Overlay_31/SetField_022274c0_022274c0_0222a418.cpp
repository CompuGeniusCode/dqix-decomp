#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern unsigned char data_ov031_02290c74[];
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a480(void);

// USA: func_ov031_0222a418  (semantic: CallStubsThenSetHandler_0222a418)
extern "C" ARM void func_ov031_0222a418(void) {
	func_ov031_0223c078(2, 0, 0x15, 8);
	func_ov031_0223cb68(0, 0x15);
	if (data_ov031_02290c74[0] != 0) {
		func_ov031_0223c078(2, 1, 1, 8);
		func_ov031_0223cb68(1, 1);
	}
	SetField_022274c0_022274c0((int)func_ov031_0222a480);
}
