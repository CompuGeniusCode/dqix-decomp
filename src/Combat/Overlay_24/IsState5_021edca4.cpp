#include <globaldefs.h>

struct S_state21_021edca4_inner {
	char unk[0x21];
	unsigned char state;
};

struct S_state21_021edca4 {
	char unk[0x138];
	struct S_state21_021edca4_inner* inner;
};

// USA: func_ov024_021edca4
ARM int IsState5_021edca4(struct S_state21_021edca4* obj) {
	int result = obj->inner->state == 5;
	return result != 0;
}
