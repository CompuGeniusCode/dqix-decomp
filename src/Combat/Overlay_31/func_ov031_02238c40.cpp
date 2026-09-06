#include <globaldefs.h>

extern unsigned short* data_ov031_02290d14;
int CheckSlotFlag7_021d8aec(int id);

// USA: func_ov031_02238c40
extern "C" ARM int func_ov031_02238c40(void) {
	unsigned short i;

	if (data_ov031_02290d14[1] == 0) return 0;
	i = 1;
	do {
		if (data_ov031_02290d14[1] & (1 << i)) {
			if (CheckSlotFlag7_021d8aec(i) == 0) return 0;
		}
		i++;
	} while (i < 16);
	return 1;
}
