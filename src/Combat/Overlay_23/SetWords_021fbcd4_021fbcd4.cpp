#include <globaldefs.h>

struct Words021fbcd4 { unsigned int a, b, c; };

// USA: func_ov023_021fbcd4
ARM void SetWords_021fbcd4_021fbcd4(void* obj, struct Words021fbcd4* src) {
	struct Words021fbcd4* dst = (struct Words021fbcd4*)((char*)obj + 0x20);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
