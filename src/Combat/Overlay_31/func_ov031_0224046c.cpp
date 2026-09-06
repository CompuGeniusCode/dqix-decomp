#include <globaldefs.h>

// USA: func_ov031_0224046c  (semantic: ReadStreamChunkByte_0224046c)
#pragma optimize_for_size off
extern "C" ARM signed char func_ov031_0224046c(void* obj, void** chain, int* counter) {
	if (*chain == 0) {
		if (*counter < 0x400) {
			int c = *counter;
			*counter = c + 1;
			return *((signed char*)obj + c + 0x20);
		}
		*counter = 0;
		*chain = *(void**)((char*)obj + 0x1c);
	} else {
		if (*counter == 0x200) {
			*counter = 0;
			*chain = *(void**)*chain;
		}
	}
	int c = *counter;
	*counter = c + 1;
	return *((signed char*)*chain + c + 4);
}
