#include <globaldefs.h>

struct Rec_021c90f8 { unsigned short a; short b; unsigned short c; unsigned short d; unsigned short e; unsigned char f; };

// USA: func_ov017_021c90f8
ARM void CopyRec_021c90f8(Rec_021c90f8* dst, Rec_021c90f8* src) {
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
	dst->d = src->d;
	dst->e = src->e;
	dst->f = src->f;
}
