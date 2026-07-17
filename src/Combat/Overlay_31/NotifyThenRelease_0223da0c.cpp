#include <globaldefs.h>

void TailCallForward_0223e2e0(int, int);
void FreeAndClearPtr_0223cf70(void*);
extern void* data_ov031_02290d60;

// USA: func_ov031_0223da0c
ARM void NotifyThenRelease_0223da0c(void) {
	int v = *(int*)((char*)data_ov031_02290d60 + 0x808);
	TailCallForward_0223e2e0(1, v);
	FreeAndClearPtr_0223cf70(&data_ov031_02290d60);
}
