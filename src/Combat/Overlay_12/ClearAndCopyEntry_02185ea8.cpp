#include <globaldefs.h>
#include "std_library_functions.h"

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(List0202fec8 *obj, int id, int *out1, int *out2);

extern "C" void func_020301c8(int a, int b);

// USA: func_ov012_02185ea8
ARM void ClearAndCopyEntry_02185ea8(char *self) {
	int id = GetData02104304Field4();
	int field = *(int *)(self + 0x1384);
	int out1;
	GetListEntryValues0202fec8((List0202fec8 *)id, field, &out1, (int*)(self + 0x13b8));
	memcpy(*(void**)(self + 0x13b4), (void*)out1, *(int*)(self + 0x13b8));
	func_020301c8(id, *(int *)(self + 0x1384));
	*(int *)(self + 0x1384) = -1;
}
