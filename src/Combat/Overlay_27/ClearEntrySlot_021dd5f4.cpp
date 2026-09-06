#include <globaldefs.h>
#include "System/Memory.h"

struct RootStruct021dd5f4 {
	char pad[4];
	void *arr;
};

extern struct RootStruct021dd5f4 data_ov027_021e3424;

// USA: func_ov027_021dd5f4
ARM void ClearEntrySlot_021dd5f4(int index) {
	void *base = data_ov027_021e3424.arr;
	if (base != NULL) {
		int idx = index - 1;
		VectorizedMemset((char *)base + (idx << 5), 0, 0x1e);
		*(int *)((char *)data_ov027_021e3424.arr + (idx << 2) + 0x1e0) = 0;
	}
}
