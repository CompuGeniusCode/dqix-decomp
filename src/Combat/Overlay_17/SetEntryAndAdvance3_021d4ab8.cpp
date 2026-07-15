#include <globaldefs.h>

struct Entry_021d4ab8 { int type; int val; };
struct S1_021d4ab8 { unsigned char pad[0x14]; Entry_021d4ab8* cursor; };

// USA: func_ov017_021d4ab8
ARM void SetEntryAndAdvance3_021d4ab8(S1_021d4ab8* obj, int val) {
	obj->cursor->type = 3;
	Entry_021d4ab8* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
