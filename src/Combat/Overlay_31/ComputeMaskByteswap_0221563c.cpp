#include <globaldefs.h>

// USA: func_ov031_0221563c
ARM unsigned int ComputeMaskByteswap_0221563c(int n) {
	int bits = 0x20 - n;
	unsigned int v = 0xffffffff;
	int i = 0;
	if (bits > 0) {
		do {
			i++;
			v = v << 1;
		} while (i < bits);
	}
	return ((v >> 0x18) & 0xff) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | ((v << 0x18) & 0xff000000);
}
