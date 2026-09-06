#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
int GetField9OrZero_022134b0(void);

// USA: func_ov031_022134cc
ARM void SetFieldCAndA_022134cc(int v) {
	char *p = func_ov031_022133f8(1);
	*(int*)(p + 0xc) = v;
	*(p + 0xa) = (unsigned char)GetField9OrZero_022134b0();
}
