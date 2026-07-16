#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* _Z15GetBattleStructv();
int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(List0202fec8 *obj, int id, int *out1, int *out2);

extern "C" void func_020dfec0(void *a, void *b, int c, int d);
extern "C" void func_020301c8(int a, int b);

// USA: func_ov012_02185f04
ARM void ResetAndRebuildEntry_02185f04(char *self) {
	_Z15GetBattleStructv();
	int id = GetData02104304Field4();
	int field = *(int *)(self + 0x1388);
	int out1, out2;
	GetListEntryValues0202fec8((List0202fec8 *)id, field, &out1, &out2);
	((SafeAllocator *)(self + 0x84))->Reset();
	func_020dfec0(self + 0x1344, self + 0x84, out1, out2);
	func_020301c8(id, *(int *)(self + 0x1388));
	*(int *)(self + 0x1388) = -1;
}
