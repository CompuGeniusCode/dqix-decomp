#include <globaldefs.h>

struct Entry_021d4a98 { int type; int val; };
struct S1_021d4a98 { unsigned char pad[0x14]; Entry_021d4a98* cursor; };

// USA: func_ov017_021d4a98
ARM void SetEntryAndAdvance2_021d4a98(S1_021d4a98* obj, int val) {
	obj->cursor->type = 2;
	Entry_021d4a98* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
