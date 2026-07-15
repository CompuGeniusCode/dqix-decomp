#include <globaldefs.h>

struct Words021edf38 { unsigned int a, b, c; };

// USA: func_ov023_021edf38
ARM void SetWords_021edf38_021edf38(void* obj, struct Words021edf38* src) {
	struct Words021edf38* dst = (struct Words021edf38*)((char*)obj + 0x0);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
