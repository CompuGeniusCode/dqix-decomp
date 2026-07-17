#include <globaldefs.h>

extern void (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_0220a66c
#pragma optimize_for_size off
ARM void ReleaseHandleIfFull_0220a66c(int count, char* self) {
	char* ctx = *(char**)(self + 0xc);
	unsigned int avail = *(int*)(ctx + 0x828) - *(int*)(ctx + 0x82c);
	if ((unsigned int)count >= avail) {
		void* handle = *(void**)(ctx + 0x824);
		if (handle != 0) {
			data_ov031_0224c9c0(handle);
		}
		*(void**)(ctx + 0x824) = 0;
		return;
	}
	*(int*)(ctx + 0x82c) += count;
}
