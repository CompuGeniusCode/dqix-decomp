#include <globaldefs.h>

struct DataObj0224e5ac2 { void* (*field0)(void*, void*, int); };
extern struct DataObj0224e5ac2 data_ov031_0224e5ac;
struct XType0221b98 { int f0; int f4; };
XType0221b98* SubtractOffset20_02211b20(int);

// USA: func_ov031_02211b98
ARM void* Alloc_02211b98(void *a, int b) {
	if (b == 0) return a;
	XType0221b98 *x = SubtractOffset20_02211b20(b);
	return data_ov031_0224e5ac.field0(a, x, x->f4 + 0x20);
}
