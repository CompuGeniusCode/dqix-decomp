#include <globaldefs.h>

// USA: func_ov000_02167434
ARM void ClearBitIfValueFound02167434(unsigned char* obj, int value) {
	int i;
	for (i = 0; i < obj[0x5e00]; i++) {
		if (*(int*)(obj + 0x5e04 + i * 4) == value) {
			obj[0x5e01] &= ~(1 << i);
			return;
		}
	}
}
