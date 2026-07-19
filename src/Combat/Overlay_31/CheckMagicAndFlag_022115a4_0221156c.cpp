#include <globaldefs.h>

ARM int CheckMagicAndFlag_022115a4(int *obj);
extern "C" unsigned int func_ov031_02211720(void *a);

struct S0221156c {
	char pad[0x3c];
	unsigned int field3c;
};

// USA: func_ov031_0221156c  (semantic: VerifyChecksum_0221156c)
extern "C" ARM int func_ov031_0221156c(S0221156c *p) {
	if (!CheckMagicAndFlag_022115a4((int*)p)) return 0;
	return p->field3c == func_ov031_02211720(p);
}
