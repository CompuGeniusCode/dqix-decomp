#include <globaldefs.h>

extern "C" unsigned int func_ov031_022005b4(void* p, unsigned int len, unsigned int seed);

// USA: func_ov031_022006a0
ARM int IsChecksumValid_022006a0(void* a, unsigned int len, void* c, unsigned int seed) {
	unsigned int sum = func_ov031_022005b4(a, len, seed);
	sum = func_ov031_022005b4((char*)c + 0xc, 8, sum);
	unsigned int v = sum + len;
	if (v & 0x10000) {
		v = (unsigned short)(v + 1);
	}
	return v != 0xffff;
}
