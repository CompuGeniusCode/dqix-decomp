#include <globaldefs.h>

// USA: func_ov031_0220c92c
ARM void ShortArrayToBytesBE_0220c92c(unsigned char* dst, unsigned short* src, int count) {
	dst = dst + (count - 1);
	if (count > 1) {
		do {
			unsigned short v = *src;
			count -= 2;
			*dst-- = (unsigned char)v;
			v = *src++;
			*dst-- = (unsigned char)(v >> 8);
		} while (count > 1);
	}
	if (count > 0) {
		*dst = (unsigned char)*src;
	}
}
