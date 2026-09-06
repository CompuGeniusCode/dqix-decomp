#include <globaldefs.h>

// USA: func_ov031_02200668
ARM unsigned int NormalizeChecksum_02200668(unsigned int value) {
	unsigned short v = (unsigned short)(value ^ 0xffff);
	if (v == 0) {
		return 0xffff;
	}
	return v;
}
