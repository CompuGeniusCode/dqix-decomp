#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);

struct Obj021685a8 { char pad[0x4ec]; unsigned char field4ec; };

// USA: func_ov003_021685a8  (semantic: CallInitEntriesIfSet_021685a8)
extern "C" ARM void func_ov003_021685a8(struct Obj021685a8* obj) {
	if (obj->field4ec == 0) return;
	InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + 0xe4));
}
