#include <globaldefs.h>

extern char* data_ov031_02290d9c;
int PushSlotAndCheckIndex_0223bf48(int);

// USA: func_ov031_0223e2c0
ARM int TailCallField4_0223e2c0(int idx) {
	int v = *(int*)(data_ov031_02290d9c + (idx << 6) + 4);
	return PushSlotAndCheckIndex_0223bf48(v);
}
