#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct EntryManager020e2490;
void InitEntryManager020e2490(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);

struct Obj02159c24 { char pad[0xe64]; struct EntryManager020e2490* mgr; char pad2[0xe68 - 0xe64 - 4]; int field_e68; };

// USA: func_ov005_02159c24
ARM void InitEntryManagerAndAllocator02159c24(Obj02159c24* obj, int arg1, int arg2) {
	((SafeAllocator*)((char*)obj + 0x280))->Reset();
	void* mem = ((SafeAllocator*)((char*)obj + 0x280))->Allocate(0x24);
	obj->mgr = (struct EntryManager020e2490*)mem;
	InitEntryManager020e2490(obj->mgr, 0, 1, (void*)arg1, (SafeAllocator*)((char*)obj + 0x280), 4, 0x40);
	obj->field_e68 = arg2;
}
