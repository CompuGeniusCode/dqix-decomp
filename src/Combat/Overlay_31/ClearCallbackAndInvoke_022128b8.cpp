#include <globaldefs.h>
#include "System/ProcessorContext.h"

void* CallWithTag6Zero_022127a8(void* a);

struct Ctx0224e5c0_022128b8 {
	char pad[4];
	void (*field4)(void);
	char pad2[0x9c0 - 8];
	ProcessorContext field9c0;
};

extern Ctx0224e5c0_022128b8* data_ov031_0224e5c0;

// USA: func_ov031_022128b8  (semantic: ClearCallbackAndInvoke_022128b8)
extern "C" ARM void func_ov031_022128b8(void) {
	AwaitContextCompletion(&data_ov031_0224e5c0->field9c0);
	void (*callback)(void) = data_ov031_0224e5c0->field4;
	CallWithTag6Zero_022127a8(data_ov031_0224e5c0);
	data_ov031_0224e5c0 = NULL;
	if (callback != NULL) callback();
}
