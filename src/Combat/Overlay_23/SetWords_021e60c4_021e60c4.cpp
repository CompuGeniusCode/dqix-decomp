#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };

// USA: func_ov023_021e60c4
ARM void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src) {
	struct Words021e60c4* dst = (struct Words021e60c4*)((char*)obj + 0x50);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
