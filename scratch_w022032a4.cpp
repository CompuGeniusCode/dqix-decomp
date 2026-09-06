#include <globaldefs.h>
#include "System/Timing.h"
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

extern "C" void* func_ov031_02203120(void* obj);
extern "C" int func_ov031_02201f10(void* obj, int mode, int size);

struct GlobalStruct0224c980_022032a4 {
	char pad[0x50];
	int field50;
};

extern GlobalStruct0224c980_022032a4 data_ov031_0224c980;

// USA: func_ov031_022032a4
extern "C" ARM int func_ov031_022032a4(void* obj) {
	unsigned int attempts;
	void* handle = func_ov031_02203120(obj);
	attempts = 0;
	for (;;) {
		*(void**)((char*)obj + 0x28) = handle;
		*(unsigned char*)((char*)obj + 0x8) = 2;
		*(unsigned int*)((char*)obj + 0x10) = (unsigned int)(GetCurrentTimestamp() >> 16);
		func_ov031_02201f10(obj, 2, 0x18);
		int priorState = DisableIRQInterrupts();
		if (*(unsigned char*)((char*)obj + 0x8) == 2 && data_ov031_0224c980.field50 != 0) {
			*(int*)((char*)obj + 4) = 1;
			BlockCurrentContext(NULL);
		}
		SetIRQInterruptState(priorState);
		if (*(unsigned char*)((char*)obj + 0x8) == 4) {
			return 0;
		}
		if (data_ov031_0224c980.field50 == 0) {
			break;
		}
		attempts++;
		if (attempts >= 3) {
			break;
		}
	}
	return 1;
}
