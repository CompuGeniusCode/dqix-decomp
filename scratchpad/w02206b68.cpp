#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

extern "C" int func_020c7ea0(void* obj, unsigned int* out, int canWait);
extern "C" void func_020c7e0c(void* data, int a, int b);
extern void CallGlobalWithArg_02205174(int v);

struct QueueNode02206b68 { char pad[8]; void* field8; };

// USA: func_ov031_02206b68
extern "C" ARM void AwaitAndDrainQueue_02206b68(char* obj) {
	if (obj == 0) {
		return;
	}
	AwaitContextCompletion((ProcessorContext*)(obj + 0x20));
	int prevState = DisableIRQInterrupts();
	AddContextSwitchLock();

	unsigned int cursor;
	if (func_020c7ea0(obj, &cursor, 0)) {
		do {
			if (cursor != 0) {
				if (((struct QueueNode02206b68*)cursor)->field8 != 0) {
					func_020c7e0c(((struct QueueNode02206b68*)cursor)->field8, -11, 0);
				}
				CallGlobalWithArg_02205174((int)cursor);
			}
		} while (func_020c7ea0(obj, &cursor, 0));
	}

	RemoveContextSwitchLock();
	SwitchContextUninterrupted();
	SetIRQInterruptState(prevState);
}
