#include <globaldefs.h>

// USA: func_ov031_0221b1cc
ARM int HasNonZeroByte32_0221b1cc(unsigned char* arr) {
	int i = 0;
	do {
		if (arr[i] != 0) return 1;
		i++;
	} while (i < 32);
	return 0;
}
