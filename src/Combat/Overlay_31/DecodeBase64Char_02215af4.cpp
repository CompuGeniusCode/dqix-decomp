#include <globaldefs.h>

// USA: func_ov031_02215af4
ARM int DecodeBase64Char_02215af4(unsigned int c) {
	unsigned int t;
	if (c >= 0x41 && c <= 0x5a) return c - 0x41;
	if (c >= 0x61 && c <= 0x7a) {
		t = c - 0x61;
		return t + 0x1a;
	}
	if (c >= 0x30 && c <= 0x39) {
		t = c - 0x30;
		return t + 0x34;
	}
	if (c == 0x2b) return 0x3e;
	if (c == 0x2f) return 0x3f;
	return (c == 0x3d) ? 0 : -1;
}
