#include <globaldefs.h>

struct S021a4e70 { char pad[0x54]; signed char field; };

// USA: func_ov017_021a4e70
ARM int IsFieldNotPositive_021a4e70(unsigned char* base) {
	S021a4e70* s = (S021a4e70*)(base + 0x4300);
	return s->field <= 0;
}
