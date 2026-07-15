#include <globaldefs.h>

// USA: func_ov031_02200824
ARM int CompareThreeU16sDiffer02200824(unsigned short* a, unsigned short* b) {
	int i = 0;
	do {
		if (*a++ != *b++) return 1;
		i++;
	} while (i < 3);
	return 0;
}
