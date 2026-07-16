#include <globaldefs.h>

extern "C" unsigned int func_ov031_022005b4(void* p, unsigned int len, unsigned int seed);
unsigned int NormalizeChecksum_02200668(unsigned int value);

// USA: func_ov031_02200684
ARM unsigned int ComputeNormalizedChecksum_02200684(void* p, unsigned int len) {
	unsigned int sum = func_ov031_022005b4(p, len, 0);
	return NormalizeChecksum_02200668((unsigned short)sum);
}
