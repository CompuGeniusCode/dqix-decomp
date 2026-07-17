#include <globaldefs.h>

// USA: func_ov031_0220bdcc
ARM int CompareShortArraysDesc_0220bdcc(unsigned short* a, unsigned short* b, int count) {
	int i = count - 1;
	if (i >= 0) {
		do {
			unsigned short bv = b[i];
			unsigned short av = a[i];
			if (av > bv) return 1;
			if (av < bv) return -1;
			i--;
		} while (i >= 0);
	}
	return 0;
}
