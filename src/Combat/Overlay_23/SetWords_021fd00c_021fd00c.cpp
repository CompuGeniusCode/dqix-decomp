#include <globaldefs.h>

struct Words021fd00c { unsigned int a, b, c; };

// USA: func_ov023_021fd00c
ARM void SetWords_021fd00c_021fd00c(void* obj, struct Words021fd00c* src) {
	struct Words021fd00c* dst = (struct Words021fd00c*)((char*)obj + 0x64);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
