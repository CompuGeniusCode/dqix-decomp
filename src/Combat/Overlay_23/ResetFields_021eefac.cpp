#include <globaldefs.h>

struct Reset_021eefac {
	int a;
	int b;
	int c;
	char pad[0x70 - 0xc];
	int d;
	char pad2[0xe3 - 0x74];
	unsigned char e;
	char pad3;
	signed char f;
};

// USA: func_ov023_021eefac
ARM void ResetFields_021eefac(struct Reset_021eefac* s) {
	s->a = 0;
	s->b = -1;
	s->c = -1;
	s->d = 0;
	s->e = 0;
	s->f = -1;
}
