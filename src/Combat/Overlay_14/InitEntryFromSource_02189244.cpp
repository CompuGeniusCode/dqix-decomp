#include <globaldefs.h>
#include "std_library_functions.h"

struct S02189244 { int w0; int w1; int w2; int w3; int w4; };

extern "C" int func_ov014_0218934c(S02189244* p0);
extern "C" void func_ov014_021891f0(S02189244* p0, int p3);

// USA: func_ov014_02189244
ARM int InitEntryFromSource_02189244(S02189244* dst, S02189244* src, char* flagOut, int p3) {
	*flagOut = 0;
	if (src == NULL) return 0;
	memcpy(dst, src, 0xc);
	dst->w3 = (int)src + 0xc;
	int r = func_ov014_0218934c(dst);
	dst->w4 = (int)src + (r + 0xc);
	if ((unsigned int)dst->w2 >> 31) {
		*flagOut = 1;
		return 1;
	}
	func_ov014_021891f0(dst, p3);
	dst->w2 = (dst->w2 & 0x7fffffff) | 0x80000000;
	src->w2 = (src->w2 & 0x7fffffff) | 0x80000000;
	return 1;
}
