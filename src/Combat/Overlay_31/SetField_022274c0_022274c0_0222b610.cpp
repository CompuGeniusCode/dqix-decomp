#include <globaldefs.h>

extern unsigned char data_ov031_02290c88;
extern "C" void func_ov031_0222b564(void);
ARM void SetField_022274c0_022274c0(int);

// USA: func_ov031_0222b610  (semantic: IncrementCounterThenSetHandlerIfGE120_0222b610)
extern "C" ARM void func_ov031_0222b610(void) {
	unsigned char v = ++data_ov031_02290c88;
	if (v < 0x78) return;
	SetField_022274c0_022274c0((int)func_ov031_0222b564);
}
