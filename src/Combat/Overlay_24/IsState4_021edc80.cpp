#include <globaldefs.h>

struct S_state21_021edc80_inner {
	char unk[0x21];
	unsigned char state;
};

struct S_state21_021edc80 {
	char unk[0x138];
	struct S_state21_021edc80_inner* inner;
};

// USA: func_ov024_021edc80
ARM int IsState4_021edc80(struct S_state21_021edc80* obj) {
	int result = obj->inner->state == 4;
	return result != 0;
}
