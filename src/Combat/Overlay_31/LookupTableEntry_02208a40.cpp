#include <globaldefs.h>

int FindEntryMatch_022089f4(unsigned char* data, int count, int stride, int target);
extern unsigned short data_ov031_022496fc[2];

// USA: func_ov031_02208a40
ARM int LookupTableEntry_02208a40(unsigned char* data, int count, int stride) {
	for (int i = 0; i < 2; i++) {
		if (FindEntryMatch_022089f4(data, count, stride, data_ov031_022496fc[i])) {
			return data_ov031_022496fc[i];
		}
	}
	return 0;
}
