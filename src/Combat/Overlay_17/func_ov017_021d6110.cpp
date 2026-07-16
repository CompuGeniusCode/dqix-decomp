#include <globaldefs.h>

union Value_021d6110 { int i; float f; };
struct TaggedValue_021d6110 { int type; Value_021d6110 value; };

// USA: func_ov017_021d6110
extern "C" ARM float func_ov017_021d6110(TaggedValue_021d6110 *a) {
	if (a->type != 0) {
		return a->value.f;
	}
	return (float)a->value.i;
}
