#include <globaldefs.h>

int TrySetActionFromListEntry(void*, int, int);
extern void* data_ov031_02290d00;

// USA: func_ov031_02236878
extern "C" ARM int func_ov031_02236878(int index) {
	return TrySetActionFromListEntry((char*)data_ov031_02290d00 + 0x94, 0, index);
}
