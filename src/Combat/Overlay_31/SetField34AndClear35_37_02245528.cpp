#include <globaldefs.h>

struct Struct_02245528 { unsigned char pad[0x34]; unsigned char f34; unsigned char f35; unsigned char f36; unsigned char f37; };

// USA: func_ov031_02245528
ARM void SetField34AndClear35_37_02245528(struct Struct_02245528* p, int v) {
	p->f34 = v;
	p->f35 = 0;
	p->f37 = 0;
	if (v == 0) {
		p->f36 = 1;
	}
}
