#include <globaldefs.h>
#include "System/Memory.h"

ARM int TrimTrailingZeroShorts_0220bb24(unsigned short* arr, int len);

// USA: func_ov031_0220bee4
ARM void MultiplyShortArrayByScalar_0220bee4(unsigned short* dst, unsigned short* src, int scalar, int len) {
	int n = TrimTrailingZeroShorts_0220bb24(src, len);
	int carry = 0;
	int i = 0;
	if (n > 0) {
		do {
			int v = scalar * src[i] + carry;
			dst[i] = (unsigned short)v;
			i++;
			carry = (unsigned int)v >> 16;
		} while (i < n);
	}
	if (i < len) {
		dst[i] = (unsigned short)carry;
		i++;
	}
	VectorizedMemset(dst + i, 0, (len - i) * 2);
}
