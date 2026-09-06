#include <globaldefs.h>

// USA: func_ov001_0215b598  (semantic: SetPowcntDisplaySwap_0215b598)
extern "C" ARM void func_ov001_0215b598(int on) {
	volatile unsigned short* powcnt = (volatile unsigned short*)0x4000304;
	*powcnt = (*powcnt & ~0x8000) | (on << 15);
}
