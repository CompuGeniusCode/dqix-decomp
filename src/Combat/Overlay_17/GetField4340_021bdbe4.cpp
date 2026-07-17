#include <globaldefs.h>

struct S021bdbe4 { char pad[0x340]; int value; };

// USA: func_ov017_021bdbe4
ARM int GetField4340_021bdbe4(unsigned char* base) {
	S021bdbe4* s = (S021bdbe4*)(base + 0x4000);
	return s->value;
}
