#include <globaldefs.h>

extern void* data_ov031_0224e580;
int func_020c7ea0(void* data, int* out, int count);

// USA: func_ov031_0220f6e0
#pragma optimize_for_size off
ARM void PopQueueEntryAndSet1c_0220f6e0(void) {
	int local;
	func_020c7ea0(data_ov031_0224e580, &local, 0);
	void* val = *(void**)((char*)data_ov031_0224e580 + 0x24);
	if (val == NULL) return;
	*(int*)((char*)val + 0x1c) = 1;
	*(void**)((char*)data_ov031_0224e580 + 0x24) = NULL;
}
