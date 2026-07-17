#include <globaldefs.h>

// USA: func_ov031_022089f4
ARM int FindEntryMatch_022089f4(unsigned char* data, int count, int stride, int target) {
	for (int i = 0; i < count; i++, data += stride) {
		int val = (data[0] << 8) + data[1];
		if (stride == 3) {
			val = (val << 8) + data[2];
		}
		if (val == target) {
			return 1;
		}
	}
	return 0;
}
