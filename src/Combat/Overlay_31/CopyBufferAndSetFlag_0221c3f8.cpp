#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

struct Buf0221c3f8 { unsigned long long u0; unsigned long long u1; int pad; };
struct Dest0221c3f8 { unsigned long long u0; unsigned long long u1; int flag; };

// USA: func_ov031_0221c3f8  (semantic: CopyBufferAndSetFlag_0221c3f8)
extern "C" ARM void func_ov031_0221c3f8(struct Dest0221c3f8* dest) {
	struct Buf0221c3f8 buf;
	func_ov031_0221ae00(&buf);
	dest->u0 = buf.u0;
	dest->u1 = buf.u1;
	dest->flag = buf.u0 != 0;
}
