#include <globaldefs.h>

struct SmallStruct10_021f6a4c { unsigned int w0; unsigned char b4, b5, b6, b7, b8, b9; };

// USA: func_ov024_021f6a4c  (semantic: CopyStruct10Bytes_021f6a4c)
extern "C" ARM void func_ov024_021f6a4c(struct SmallStruct10_021f6a4c* dst, struct SmallStruct10_021f6a4c* src) {
	dst->w0 = src->w0;
	dst->b4 = src->b4;
	dst->b5 = src->b5;
	dst->b6 = src->b6;
	dst->b7 = src->b7;
	dst->b8 = src->b8;
	dst->b9 = src->b9;
}
