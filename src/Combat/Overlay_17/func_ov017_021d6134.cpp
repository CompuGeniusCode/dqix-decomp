#include <globaldefs.h>

struct TaggedPtr_021d6134 { int type; int *ptr; };

// USA: func_ov017_021d6134
extern "C" ARM void func_ov017_021d6134(TaggedPtr_021d6134 *a, int val) {
	if (a->type == 3) {
		a->ptr[1] = val;
	}
}
