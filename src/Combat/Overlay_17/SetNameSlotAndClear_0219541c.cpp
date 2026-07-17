#include <globaldefs.h>
#include "std_library_functions.h"

struct SearchStruct;
extern "C" void* func_0202ae18(void);
void ClearSearchFlagBit0202c600(struct SearchStruct* obj, int value);
extern "C" void func_ov017_02195214(void* dst, void* src);

// USA: func_ov017_0219541c
ARM void SetNameSlotAndClear_0219541c(void* obj, int idx, char* namePtr) {
	void* searchObj = func_0202ae18();
	int idx1 = idx - 1;
	unsigned char* ptr;
	if (idx1 < 0) return;
	if (idx1 > 2) return;
	func_ov017_02195214((unsigned char*)obj + 0xf1 + 0x4200 + idx1 * 15, namePtr);
	ClearSearchFlagBit0202c600((struct SearchStruct*)searchObj, idx);
	ptr = *(unsigned char**)((char*)obj + 0x4000 + 0x41c);
	if (ptr[0] != 1) return;
	if (ptr[2] != idx) return;
	strcpy((char*)ptr + 4, namePtr + 2);
}
