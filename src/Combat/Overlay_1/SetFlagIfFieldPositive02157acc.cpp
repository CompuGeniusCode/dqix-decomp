#include <globaldefs.h>

struct Struct02157acc {
	unsigned char pad0[0xc4];
	int field0xc4;
	unsigned char pad1[0x464 - 0xc8];
	int field0x464;
};

// USA: func_ov001_02157acc
ARM void SetFlagIfFieldPositive02157acc(struct Struct02157acc* s) {
	if (s->field0xc4 > 0) {
		s->field0x464 = 1;
	}
}
