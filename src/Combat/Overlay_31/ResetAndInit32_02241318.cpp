#include <globaldefs.h>

extern int data_ov031_0229199c;
extern "C" void func_020c9b10(void*);
extern "C" void func_ov031_02209e28(void*, int);

// USA: func_ov031_02241318
ARM void ResetAndInit32_02241318(void) {
	func_020c9b10(&data_ov031_0229199c);
	func_ov031_02209e28(&data_ov031_0229199c, 0x20);
}
