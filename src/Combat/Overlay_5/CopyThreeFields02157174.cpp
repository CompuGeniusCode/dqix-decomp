#include <globaldefs.h>

struct Src02157174 { int a; int b; int c; };
struct Dst02157174 { char pad[0x1c]; int a; int b; int c; };

// USA: func_ov005_02157174
ARM void CopyThreeFields02157174(Dst02157174* dst, Src02157174* src) {
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
