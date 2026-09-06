#include <globaldefs.h>

struct IntBytePair021dbb20 { int a; unsigned char b; };

// USA: func_ov023_021dbb20
ARM void CopyIntAndByte_021dbb20(struct IntBytePair021dbb20* dst, struct IntBytePair021dbb20* src) {
	dst->a = src->a;
	dst->b = src->b;
}
