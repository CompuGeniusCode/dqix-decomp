#include <globaldefs.h>

struct Pair021fb878 {
	unsigned int a;
	unsigned int b;
};

struct Dst021fb878 {
	char pad[0xa8];
	unsigned int a;
	unsigned int b;
};

// USA: func_ov023_021fb878
ARM void CopyPairFields_021fb878(struct Dst021fb878 *dst, struct Pair021fb878 *src) {
	dst->a = src->a;
	dst->b = src->b;
}
