#include <globaldefs.h>

// USA: func_ov031_02216710
ARM int IsPrintableRun10_02216710(unsigned char *s) {
	int i = 0;
	do {
		unsigned char c = s[i];
		if (c < 0x20 || c > 0x7e) return 0;
		i++;
	} while (i < 0xa);
	return 1;
}
