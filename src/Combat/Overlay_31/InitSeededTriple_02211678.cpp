#include <globaldefs.h>

extern "C" void func_020c9b10(unsigned int *buf);

struct SeededTriple02211678 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
};

// USA: func_ov031_02211678
ARM void InitSeededTriple_02211678(SeededTriple02211678 *out, int a, int b) {
	unsigned int buf[8];
	int i;
	func_020c9b10(buf);
	for (i = 1; i < 8; i++) {
		unsigned int *p = &buf[i];
		*p ^= p[-1];
	}
	unsigned long long v = 0x5d588b656c078965ULL * buf[7] + 0x269ec3;
	out->field4 = a & 0xffffffffu;
	out->field0 = b & 0xffffffffu;
	out->field8 = (unsigned int)(v >> 32);
}
