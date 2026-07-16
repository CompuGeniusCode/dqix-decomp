#include <globaldefs.h>

struct IndexedArrayStruct02189380;
int* GetIndexedSlot_02189380(struct IndexedArrayStruct02189380* s);

struct EntryBuf_02189398 {
	char pad0[4];
	unsigned short count;
	char pad6[6];
	int* arr;
};

// USA: func_ov014_02189398
ARM int* AllocAlignedSlot_02189398(struct EntryBuf_02189398* s) {
	int* arr = s->arr;
	int off = (int)GetIndexedSlot_02189380((struct IndexedArrayStruct02189380*)s) + (s->count << 1) - (int)arr;
	off = (off + 3) & ~3;
	return (int*)((char*)arr + off);
}
