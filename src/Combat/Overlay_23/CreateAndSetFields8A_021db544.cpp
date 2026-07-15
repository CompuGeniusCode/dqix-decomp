#include <globaldefs.h>

extern "C" void* func_ov023_021db4e4(void*, void*, int, int);

struct Obj021db544 { char pad[0x8]; short field8; short fielda; };

// USA: func_ov023_021db544
ARM void* CreateAndSetFields8A_021db544(void* a, void* b, int c, int d) {
	struct Obj021db544* r = (struct Obj021db544*)func_ov023_021db4e4(a, b, c, d);
	if (r != 0) {
		r->field8 = (short)c;
		r->fielda = (short)d;
	}
	return r;
}
