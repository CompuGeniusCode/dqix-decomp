#include <globaldefs.h>

struct Fields60_021f21f4 { char pad[0x60]; int f60; int f64; };

// USA: func_ov023_021f21f4
ARM int AreFields60And64AllOnes_021f21f4(struct Fields60_021f21f4* s) {
	int a = s->f60 == -1;
	int b = s->f64 == -1;
	return (a & b) != 0;
}
