#include <globaldefs.h>

struct T0221db0 { void *field0; short field4; char pad[6]; char fieldc; };
struct DataOuter0221db0 { void *pad0; struct T0221db0 *p; };
extern struct DataOuter0221db0 data_ov031_0224e5b4;
extern "C" void func_ov031_02211f24(void);

// USA: func_ov031_02211db0
ARM int Refresh_02211db0(void) {
	struct T0221db0 *p = data_ov031_0224e5b4.p;
	if (!p) return 0;
	if (p->field0) {
		p->field4 = 3;
		func_ov031_02211f24();
		return data_ov031_0224e5b4.p->fieldc != 0;
	}
	return 0;
}
