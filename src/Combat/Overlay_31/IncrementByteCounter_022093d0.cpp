#include <globaldefs.h>

// USA: func_ov031_022093d0
ARM void IncrementByteCounter_022093d0(unsigned char *p) {
	int i = 8;
	do {
		unsigned char v = *--p + 1;
		*p = v;
		if (v != 0) return;
	} while (--i != 0);
}
