#include <globaldefs.h>

struct FourSignedBytes020d9654 { signed char a, b, c, d; };

// USA: func_020d9654
ARM void CopyFourSignedBytes020d9654(struct FourSignedBytes020d9654* dst, struct FourSignedBytes020d9654* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
