#include <globaldefs.h>

struct Entry_021d4ad8 { int type; int val; };
struct S1_021d4ad8 { unsigned char pad[0x14]; Entry_021d4ad8* cursor; };

// USA: func_ov017_021d4ad8
ARM void SetEntryAndAdvance1_021d4ad8(S1_021d4ad8* obj, int val) {
	obj->cursor->type = 1;
	Entry_021d4ad8* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
