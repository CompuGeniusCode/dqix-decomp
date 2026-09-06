#include <globaldefs.h>
#include "System/Memory.h"

extern int TrimTrailingZeroShorts_0220bb24(unsigned short* arr, int len);
extern void PropagateCarryFromIndex_0220be04(unsigned short* arr, int carry, int i, int count);

#pragma optimize_for_size off
// USA: func_ov031_0220be38  (semantic: MultiplyShortArrays_0220be38)
extern "C" ARM void func_ov031_0220be38(unsigned short* dst, unsigned short* b, unsigned short* c, int n) {
	VectorizedMemset(dst, 0, n * 2);
	int lenC;
	int lenB = TrimTrailingZeroShorts_0220bb24(b, n);
	lenC = TrimTrailingZeroShorts_0220bb24(c, n);
	int i = 0;
	if (lenC <= 0) return;
	do {
		int j;
		int limit = n - i;
		for (j = 0; j < lenB && j < limit; j++) {
			int product = b[j] * c[i];
			PropagateCarryFromIndex_0220be04(dst, product, i + j, n);
		}
		i++;
	} while (i < lenC);
}
