#include <globaldefs.h>

// USA: func_ov031_0221b19c
ARM void WriteMaskBytes_0221b19c(int numBits, unsigned char *buf) {
	unsigned int allOnes = ~0u;
	unsigned int mask = allOnes ^ (allOnes >> numBits);
	int i = 0;
	int bitpos = 0;
	do {
		buf[i] = mask >> (0x18 - bitpos);
		i++;
		bitpos += 8;
	} while (i < 4);
}
