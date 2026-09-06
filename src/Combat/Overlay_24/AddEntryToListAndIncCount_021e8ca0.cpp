#include <globaldefs.h>

extern "C" int func_ov000_0215e958(int a0);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
void AppendToChainAndIncCount0215ffc4(void* obj, void* node, int idx);

struct Obj_021e8ca0 { char pad0c[0xc]; void* field0c; void* field10; };

// USA: func_ov024_021e8ca0
ARM void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id) {
	void* entry = (void*)func_ov000_0215e958((int)obj->field10);
	if (!entry) return 0;
	AddEntryAndIncrementCount0215a88c(obj->field10, entry, id);
	AppendToChainAndIncCount0215ffc4(obj->field0c, entry, 1);
	((unsigned char*)obj->field10)[0x8e02] = ((unsigned char*)obj->field10)[0x8e02] + 1;
	return entry;
}
