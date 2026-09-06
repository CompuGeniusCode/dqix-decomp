#include <globaldefs.h>

struct Inner_0223d394 { unsigned char pad[0x34]; unsigned short field34; };
struct Outer_0223d394 { unsigned char pad[4]; struct Inner_0223d394* inner; };
extern struct Outer_0223d394 data_ov031_02290d40;

// USA: func_ov031_0223d394  (semantic: CheckMaskAgainstField34_0223d394)
extern "C" ARM int func_ov031_0223d394(int mask) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) {
		return 0;
	}
	int f = data_ov031_02290d40.inner->field34;
	int w = mask & f;
	return (mask == w) ? 1 : 0;
}
