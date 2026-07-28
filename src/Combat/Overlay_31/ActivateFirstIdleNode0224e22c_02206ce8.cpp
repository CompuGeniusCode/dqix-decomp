#include <globaldefs.h>
#include "System/Interrupts.h"

struct Node02206ce8 { char pad70[0x70]; short flags; char pad7c[0xa]; Node02206ce8* next; };

extern "C" void func_ov031_02206900(void* a);
extern void* data_ov031_0224e1cc;
extern Node02206ce8* data_ov031_0224e22c;
extern void* data_ov031_0224e230;

// USA: func_ov031_02206ce8  (semantic: ActivateFirstIdleNode0224e22c_02206ce8)  (semantic: ActivateFirstIdleNode0224e22c_02206ce8)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02206ce8(void* g) {
	Node02206ce8* n;
	for (;;) {
		int state = DisableIRQInterrupts();
		n = data_ov031_0224e22c;
		if (n != 0) {
			void* cur = data_ov031_0224e1cc;
			for (;;) {
				if (n != cur) {
					if ((n->flags & 0x10) == 0) break;
				}
				n = n->next;
				if (n == 0) break;
			}
		}
		SetIRQInterruptState(state);
		if (n == 0) break;
		func_ov031_02206900(n);
	}
	if (data_ov031_0224e22c != 0) {
		if (data_ov031_0224e22c != data_ov031_0224e1cc) goto FAIL;
		if (data_ov031_0224e22c->next != 0) goto FAIL;
	}
	if (data_ov031_0224e230 != 0) goto FAIL;
	return 0;
FAIL:
	return -26;
}
