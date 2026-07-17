#include <globaldefs.h>

extern void* data_ov031_0224e580;
int func_020c7e0c(void* data, void* arg, int c);

// USA: func_ov031_0220f518
#pragma optimize_for_size off
ARM int ClearFieldsThenForward_0220f518(void* arg) {
	if (arg != NULL) {
		*(int*)((char*)arg + 0x1c) = 0;
		*(int*)((char*)arg + 0x20) = 0;
		*(int*)((char*)arg + 0x24) = 0;
	}
	if (data_ov031_0224e580 == NULL) return 0;
	return func_020c7e0c(data_ov031_0224e580, arg, 0);
}
