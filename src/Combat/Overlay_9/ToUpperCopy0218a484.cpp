#include <globaldefs.h>

// USA: func_ov009_0218a484
ARM void ToUpperCopy0218a484(int unused, char *src, char *dst) {
	int c;
	while ((c = *src) != 0) {
		if (c >= 'a' && c <= 'z') {
			c -= 0x20;
			*dst = c;
			c = *dst;
		} else {
			*dst = c;
			c = *dst;
		}
		if (c) {
			src++;
		}
		dst++;
	}
}
