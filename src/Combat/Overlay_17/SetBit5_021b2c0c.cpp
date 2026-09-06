#include <globaldefs.h>

struct S021b2c0c {
	unsigned char pad[0x38];
	union {
		unsigned int word038;
		struct {
			unsigned int b0_2 : 3;
			unsigned int bit3 : 1;
			unsigned int bit4 : 1;
			unsigned int bit5 : 1;
			unsigned int rest : 26;
		} bits;
	};
};

// USA: func_ov017_021b2c0c
ARM void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v) {
	obj->bits.bit5 = v;
}
