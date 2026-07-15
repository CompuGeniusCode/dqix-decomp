#include <globaldefs.h>

struct Fields64_021f3a8c { char pad[0x64]; int f64; int f68; };

// USA: func_ov023_021f3a8c
ARM int AreFields64And68AllOnes_021f3a8c(struct Fields64_021f3a8c* s) {
	return s->f64 == -1 && s->f68 == -1;
}
