#include <globaldefs.h>

struct KeyStruct_02187450 {
	char pad[0x1a];
	short field1a;
};

struct ObjStruct_02187450 {
	char pad[0xdc];
	int* arr;
};

// USA: func_ov014_02187450
ARM int* GetArrayEntryByField1a_02187450(struct ObjStruct_02187450* obj, struct KeyStruct_02187450* b) {
	if (!b) return NULL;
	short idx = b->field1a - 1;
	if (idx < 0) goto ret_null;
	if (idx < 0x134) {
		return obj->arr + idx;
	}
ret_null:
	return NULL;
}
