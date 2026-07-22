#include <globaldefs.h>
#include "System/Interrupts.h"

struct ListNode0224e22c_02206ce8 {
	char pad[0x70];
	short flags;
	char pad2[0xa];
	ListNode0224e22c_02206ce8* next;
};

extern "C" void* func_ov031_02206900(void* a);
extern ListNode0224e22c_02206ce8* data_ov031_0224e1cc;
extern ListNode0224e22c_02206ce8* data_ov031_0224e22c;
extern void* data_ov031_0224e230;

#pragma optimize_for_size off
// USA: func_ov031_02206ce8
extern "C" ARM int func_ov031_02206ce8(void* g) {
	ListNode0224e22c_02206ce8* node;
	for (;;) {
		int state = DisableIRQInterrupts();
		node = data_ov031_0224e22c;
		if (node != 0) {
			ListNode0224e22c_02206ce8* current = data_ov031_0224e1cc;
			for (;;) {
				if (node != current && !(node->flags & 0x10)) break;
				node = node->next;
				if (node == 0) break;
			}
		}
		SetIRQInterruptState(state);
		if (node == 0) break;
		func_ov031_02206900(node);
	}

	if (data_ov031_0224e22c == 0 || (data_ov031_0224e22c == data_ov031_0224e1cc && data_ov031_0224e22c->next == 0)) {
		if (data_ov031_0224e230 == 0) {
			return 0;
		}
	}
	return -26;
}
