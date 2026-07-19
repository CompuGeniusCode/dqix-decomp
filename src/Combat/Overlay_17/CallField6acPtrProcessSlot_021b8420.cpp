#include <globaldefs.h>

void ProcessSlot02160c60(void* work);

// USA: func_ov017_021b8420
ARM void CallField6acPtrProcessSlot_021b8420(void* obj) {
	void* p = *(void**)((char*)obj + 0x6ac);
	if (p) ProcessSlot02160c60(p);
}
