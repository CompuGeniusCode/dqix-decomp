#include <globaldefs.h>

struct IndexedArrayStruct021893c4 {
	unsigned short count;
	unsigned short unusedShort;
	int unused1;
	int unused2;
	void* arr;
};

extern "C" int func_ov014_02188b18(void* item);
extern "C" void* func_ov014_021892d4(struct IndexedArrayStruct021893c4* s, int key, int (*cmp)(void*));

// USA: func_ov014_021893c4
ARM void* FindOrGetDefaultElement_021893c4(struct IndexedArrayStruct021893c4* s, int id) {
	if (id < 0) return s->arr;
	return func_ov014_021892d4(s, id, func_ov014_02188b18);
}
