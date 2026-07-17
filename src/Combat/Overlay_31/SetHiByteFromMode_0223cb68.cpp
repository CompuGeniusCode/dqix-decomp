#include <globaldefs.h>

// USA: func_ov031_0223cb68
ARM void SetHiByteFromMode_0223cb68(int mode, int val) {
	volatile unsigned int* reg;
	if (mode == 1) reg = (volatile unsigned int*)0x4001000;
	else reg = (volatile unsigned int*)0x4000000;
	unsigned int hi = *reg & 0x1f00;
	unsigned int lo = *reg & ~0x1f00;
	*reg = lo | ((val | (hi >> 8)) << 8);
}
