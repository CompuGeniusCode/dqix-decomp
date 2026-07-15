#include <globaldefs.h>

struct Elem0215e824 {
	char pad0[0x10];
	short key;   // 0x10
	char pad1[2];
};

struct List0215e824 {
	struct Elem0215e824* base; // 0x0
	char pad0[2];
	short count;               // 0x6
};

// USA: func_ov003_0215e824
ARM struct Elem0215e824* FindElemByKey_0215e824(struct List0215e824* list, int key) {
	struct Elem0215e824* e = list->base;
	int count = list->count;
	for (int i = 0; i < count; i++, e++) {
		if (e->key == key) return e;
	}
	return NULL;
}
