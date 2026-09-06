#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

struct Buf0221c44c { unsigned long long u0; unsigned long long u1; int pad; };

#pragma optimize_for_size off
// USA: func_ov031_0221c44c  (semantic: IsBuffer0221ae00Zero_0221c44c)
extern "C" ARM int func_ov031_0221c44c(void) {
	struct Buf0221c44c buf;
	func_ov031_0221ae00(&buf);
	if (buf.u1 == 0) {
		if (buf.u0 == 0) {
			return 1;
		}
	}
	return 0;
}
