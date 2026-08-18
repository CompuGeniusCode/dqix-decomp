#include <globaldefs.h>

struct ListEntry_021842a0 {
	short id;
	char pad[0x16];
};

struct ObjStruct_021842a0 {
	char pad0[8];
	struct ListEntry_021842a0* arr;
	char pad0xc[8];
	unsigned short count;
};

// USA: func_ov014_021842a0  (semantic: FindEntryById_021842a0)
extern "C" ARM struct ListEntry_021842a0* func_ov014_021842a0(struct ObjStruct_021842a0* obj, short id) {
	struct ListEntry_021842a0* arr = obj->arr;
	if (arr == 0) return 0;
	unsigned short count = obj->count;
	if (count == 0) return 0;
	for (unsigned short i = 0; i < count; i++) {
		short v = arr[i].id;
		if (v == id) return &arr[i];
	}
	return 0;
}
