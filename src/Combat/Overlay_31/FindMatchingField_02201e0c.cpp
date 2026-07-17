#include <globaldefs.h>

extern "C" int func_ov031_02201d58(int a, int b, void* field);

extern char data_02111304;

// USA: func_ov031_02201e0c
ARM void* FindMatchingField_02201e0c(int a, int b) {
	void* field;
	void* node = *(void**)((char*)&data_02111304 + 0x8);
	if (node != NULL) {
		do {
			field = *(void**)((char*)node + 0xa4);
			if (field != NULL && *(int*)field != 0) {
				if (func_ov031_02201d58(a, b, field) != 0) {
					return field;
				}
			}
			node = *(void**)((char*)node + 0x68);
		} while (node != NULL);
	}
	return NULL;
}
