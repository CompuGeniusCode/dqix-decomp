#include <globaldefs.h>

// USA: func_ov031_02207dd4
ARM int ReadVarLenValue_02207dd4(unsigned char** pp) {
	unsigned char* p = *pp;
	unsigned char b = *p++;
	int val = b;
	if (b & 0x80) {
		int n = b & 0x7f;
		int m = n - 1;
		val = 0;
		if (n != 0) {
			do {
				if (val & 0xff000000) {
					return -1;
				}
				val = *p++ + (val << 8);
			} while (m-- != 0);
		}
	}
	*pp = p;
	return val;
}
