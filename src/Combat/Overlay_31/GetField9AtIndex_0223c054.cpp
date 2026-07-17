#include <globaldefs.h>

struct Elem_0223c054 { char pad[9]; unsigned char field9; };
extern struct Elem_0223c054* data_ov031_02290d34;

// USA: func_ov031_0223c054
ARM unsigned char GetField9AtIndex_0223c054(int which) {
	struct Elem_0223c054* e;
	if (which == 1) {
		e = data_ov031_02290d34;
	} else {
		e = (struct Elem_0223c054*)((char*)data_ov031_02290d34 + 0xc);
	}
	return e->field9;
}
