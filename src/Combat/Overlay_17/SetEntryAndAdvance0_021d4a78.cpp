#include <globaldefs.h>

struct Entry_021d4a78 { int type; int val; };
struct S1_021d4a78 { unsigned char pad[0x14]; Entry_021d4a78* cursor; };

// USA: func_ov017_021d4a78
ARM void SetEntryAndAdvance0_021d4a78(S1_021d4a78* obj, int val) {
	obj->cursor->type = 0;
	Entry_021d4a78* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
