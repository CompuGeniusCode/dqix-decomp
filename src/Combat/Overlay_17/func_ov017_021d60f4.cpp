#include <globaldefs.h>

union Value_021d60f4 { int i; float f; };
struct TaggedValue_021d60f4 { int type; Value_021d60f4 value; };

// USA: func_ov017_021d60f4
extern "C" ARM int func_ov017_021d60f4(TaggedValue_021d60f4 *a) {
	if (a->type != 1) {
		return a->value.i;
	}
	return (int)a->value.f;
}
