#include <globaldefs.h>

extern "C" int func_ov000_02156068(void* obj, int val, int zero, int one);

struct FieldRefStruct_021d8a84 { void* field0; };

// USA: func_ov024_021d8a84
ARM int CountIfFlagSet_021d8a84(struct FieldRefStruct_021d8a84* s, int unused, int val, int unused3, int unused4, int count) {
	int result = func_ov000_02156068(s->field0, (short)val, 0, 1);
	if (result) {
		return count + 1;
	}
	return count;
}
