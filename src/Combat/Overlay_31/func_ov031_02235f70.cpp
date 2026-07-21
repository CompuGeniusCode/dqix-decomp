#include <globaldefs.h>

int VariadicForward020c7130(int a, int b, ...);
extern char* data_ov031_02290cfc;
extern const char data_ov031_0224be50[];

// USA: func_ov031_02235f70  (semantic: LogFourBytes4f0_02235f70)
extern "C" ARM void func_ov031_02235f70(int a) {
	unsigned char b0 = data_ov031_02290cfc[0x4f0];
	unsigned char b1 = data_ov031_02290cfc[0x4f1];
	unsigned char b2 = data_ov031_02290cfc[0x4f2];
	unsigned char b3 = data_ov031_02290cfc[0x4f3];
	VariadicForward020c7130(a, (int)data_ov031_0224be50, b0, b1, b2, b3);
}
