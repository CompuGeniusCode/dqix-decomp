#include <globaldefs.h>

// USA: func_ov031_0220b18c
ARM void PackWordsBigEndian_0220b18c(unsigned char* dst, unsigned int* src, unsigned int len) {
	len = len >> 2;
	unsigned int i = 0;
	if (len == 0) {
		return;
	}
	do {
		unsigned int w = *src++;
		i++;
		dst[0] = w >> 24;
		dst[1] = w >> 16;
		dst[2] = w >> 8;
		dst[3] = w;
		dst += 4;
	} while (i < len);
}
