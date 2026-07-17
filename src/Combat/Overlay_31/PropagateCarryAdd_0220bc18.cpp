#include <globaldefs.h>

ARM void PropagateCarryAdd_0220bc18(unsigned short* dst, unsigned short* src, int carry, int count);

// USA: func_ov031_0220bc7c
ARM void NegateShortArray_0220bc7c(unsigned short* arr, int count) {
	int i = 0;
	if (count > 0) {
		do {
			arr[i] = ~arr[i];
			i++;
		} while (i < count);
	}
	PropagateCarryAdd_0220bc18(arr, arr, 1, count);
}
