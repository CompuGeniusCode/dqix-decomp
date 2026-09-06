#include <globaldefs.h>

struct IndexedArrayStruct02189380 {
	unsigned short a;
	unsigned short b;
	int unused1;
	int unused2;
	int* arr;
};

// USA: func_ov014_02189380
ARM int* GetIndexedSlot_02189380(struct IndexedArrayStruct02189380* s) {
	return s->arr + s->a + s->b;
}
