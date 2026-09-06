#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_02203190
#pragma optimize_for_size off
ARM void ResetSessionState02203190(void) {
	void* mgr = *((void**)&data_02111304 + 1);
	void* session = *(void**)((char*)mgr + 0xa4);
	if (session == NULL) return;
	*(unsigned char*)((char*)session + 0x8) = 10;
	*(int*)((char*)session + 0x44) = 0;
}
