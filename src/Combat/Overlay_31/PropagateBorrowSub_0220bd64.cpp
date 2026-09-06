#include <globaldefs.h>

// USA: func_ov031_0220bd64
ARM void PropagateBorrowSub_0220bd64(unsigned short* dst, unsigned short* src, int borrow, int count) {
	int i = 0;
	if (count > 0) {
		do {
			int v = src[i] - borrow;
			dst[i] = (unsigned short)v;
			borrow = ((unsigned int)v >> 16) & 1;
			if (borrow == 0) break;
			i++;
		} while (i < count);
	}
	if (dst == src) return;
	i++;
	if (i >= count) return;
	do {
		dst[i] = src[i];
		i++;
	} while (i < count);
}
