#include <globaldefs.h>

struct S0219a370 { char pad[0x78]; int count; };

// USA: func_ov017_0219a370
ARM int IsCountAtLeast4_0219a370(unsigned char* base) {
	S0219a370* s = (S0219a370*)(base + 0x4000);
	return s->count >= 4;
}
