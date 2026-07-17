#include <globaldefs.h>

struct Elem_021e27f8 {
	unsigned short field0;
	unsigned short innerCount;
	short* list;
};

struct Container_021e27f8 {
	int pad0[2];
	struct Elem_021e27f8* arr;
	int pad2[2];
	unsigned short count;
};

// USA: func_ov023_021e27f8
ARM void* FindEntryContaining_021e27f8(struct Container_021e27f8* obj, int key) {
	struct Elem_021e27f8* arr = obj->arr;
	unsigned short count = obj->count;
	unsigned short i;
	for (i = 0; i < count; i++) {
		struct Elem_021e27f8* elem = (struct Elem_021e27f8*)((char*)arr + i * 0x18);
		unsigned short innerCount = elem->innerCount;
		unsigned short j;
		for (j = 0; j < innerCount; j++) {
			if (elem->list[j] == key) return elem;
		}
	}
	return NULL;
}
