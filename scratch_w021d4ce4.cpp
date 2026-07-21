#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov017_021d4e38(void* obj, int offset);

// USA: func_ov017_021d4ce4
extern "C" ARM int UpdateField34FromKeyTable_021d4ce4(void* objIn, int key) {
	char* obj = (char*)objIn;
	if (*(int*)(obj + 0x44) == 0)
		return -1;

	*(int*)(obj + 0x14) = *(int*)(obj + 0x10);
	*(int*)(obj + 0x28) = *(int*)(obj + 0x24);
	*(int*)(obj + 0x34) = 0;

	if (key < 0) {
		char* base = *(char**)(obj + 0x44);
		*(int*)(obj + 0x34) = (int)(base + *(int*)(base + 0x4));
	} else {
		int i = 0;
		char* base = *(char**)(obj + 0x44);
		char* entry = base + *(int*)(base + 0xc);
		for (; i < *(int*)(base + 0x10); i++) {
			if (*(int*)entry == key) {
				*(int*)(obj + 0x34) = (int)(base + *(int*)(entry + 4));
				break;
			}
			entry += 8;
		}
	}

	if (*(int*)(obj + 0x34) == 0)
		return -1;

	*(int*)(obj + 0x30) = *(int*)(obj + 0x14) - (*(int*)(*(int*)(obj + 0x34) + 0xc) << 3);
	*(int*)(obj + 0x14) = *(int*)(obj + 0x30) + (*(int*)(*(int*)(obj + 0x34) + 0x8) << 3);

	memset((void*)(*(int*)(obj + 0x30) + (*(int*)(*(int*)(obj + 0x34) + 0xc) << 3)), 0,
		(*(int*)(*(int*)(obj + 0x34) + 0x8) - *(int*)(*(int*)(obj + 0x34) + 0xc)) << 3);

	*(int*)(obj + 0x3c) = 0;
	*(int*)(obj + 0x40) = 0;
	*(int*)(obj + 0x50) = 0;
	func_ov017_021d4e38(obj, *(int*)(obj + 0x48) + *(int*)(*(int*)(obj + 0x34)));

	return *(int*)(obj + 0x3c) == 0;
}
