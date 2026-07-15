#include <globaldefs.h>

struct Bits0_0215f56c { signed char flag0 : 6; signed char rest0 : 2; };
struct Word154_0215f56c { unsigned int pad0 : 10; unsigned int val : 10; unsigned int rest : 12; };
struct Word158_0215f56c { unsigned int val : 10; unsigned int rest : 22; };

struct S0215f56c {
	struct Bits0_0215f56c bits0;
	char pad[0x154 - 4];
	struct Word154_0215f56c w154;
	struct Word158_0215f56c w158;
};

// USA: func_ov003_0215f56c
ARM int ClassifyRatio_0215f56c(struct S0215f56c* obj) {
	int result = 0xf;
	if (obj != NULL) {
		if (obj->bits0.flag0 >= 0) {
			float a = (float)(unsigned int)obj->w154.val;
			float b = (float)(unsigned int)obj->w158.val;
			float ratio = a / b;
			if (ratio <= 0.25f) result = 0xd;
			if (ratio <= 0.08f) result = 0xb;
		}
	}
	return result;
}
