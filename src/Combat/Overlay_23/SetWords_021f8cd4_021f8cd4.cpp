#include <globaldefs.h>

struct Words021f8cd4 { unsigned int a, b, c; };

// USA: func_ov023_021f8cd4
ARM void SetWords_021f8cd4_021f8cd4(void* obj, struct Words021f8cd4* src) {
	struct Words021f8cd4* dst = (struct Words021f8cd4*)((char*)obj + 0x24);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
