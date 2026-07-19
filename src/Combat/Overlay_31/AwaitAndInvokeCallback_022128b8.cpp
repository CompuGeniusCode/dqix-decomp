#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Ctx022128b8 { unsigned char pad0[4]; void (*funcField4)(void); };
struct Data0224e5c0 { Ctx022128b8* field0; };
extern Data0224e5c0 data_ov031_0224e5c0;
void* CallWithTag6Zero_022127a8(void* a);

// USA: func_ov031_022128b8  (semantic: AwaitAndInvokeCallback_022128b8)
extern "C" ARM void func_ov031_022128b8(void) {
	Ctx022128b8* p = data_ov031_0224e5c0.field0;
	AwaitContextCompletion((ProcessorContext*)((char*)p + 0x9c0));
	p = data_ov031_0224e5c0.field0;
	void (*fn)(void) = p->funcField4;
	CallWithTag6Zero_022127a8(p);
	data_ov031_0224e5c0.field0 = NULL;
	if (fn) fn();
}
