#include <globaldefs.h>

// USA: func_ov031_02229c1c  (semantic: SetBgPrioritiesToBack_02229c1c)
extern "C" ARM void func_ov031_02229c1c(void) {
	volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
	volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
	*subBg0 = (*subBg0 & ~3) | 3;
	*(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
	*bg0 = (*bg0 & ~3) | 3;
	*bg1 = (*bg1 & ~3) | 3;
	*(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
