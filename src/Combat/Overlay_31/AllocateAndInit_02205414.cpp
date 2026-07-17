#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

struct Manager_02205414 {
	char pad[0x18];
	void* (*alloc)(int size);
};

extern Manager_02205414* data_ov031_022496a4;

int GetTotalSize_0220547c(int obj);
extern "C" void func_ov031_02205524(void* p, int obj);
void EnqueueItem0224e22c_022070c8(void* p);

// USA: func_ov031_02205414
ARM void* AllocateAndInit_02205414(int obj) {
	int size = GetTotalSize_0220547c(obj);
	void* p;
	int oldIRQ = DisableIRQInterrupts();
	p = data_ov031_022496a4->alloc(size);
	if (p != NULL) {
		VectorizedMemset(p, 0, size);
		func_ov031_02205524(p, obj);
		EnqueueItem0224e22c_022070c8(p);
	}
	SetIRQInterruptState(oldIRQ);
	return p;
}
