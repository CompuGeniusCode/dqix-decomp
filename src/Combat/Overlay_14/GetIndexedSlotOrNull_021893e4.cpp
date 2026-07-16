#include <globaldefs.h>

struct ArrayStruct021893e4 {
	unsigned short idx;
	int unused1;
	int unused2;
	int* arr;
};

struct KeyStruct021893e4 {
	short unused0;
	unsigned short field : 12;
};

// USA: func_ov014_021893e4
ARM int* GetIndexedSlotOrNull_021893e4(struct ArrayStruct021893e4* a, struct KeyStruct021893e4* b) {
	if (!b) return NULL;
	return a->arr + a->idx + b->field;
}
