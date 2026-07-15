#include <globaldefs.h>

struct Obj0204b010;
void ClearBuffer0204b010(struct Obj0204b010* obj, void* p);

struct Obj28_021f7864 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021f7864
ARM void ClearBufferIfNotFlag0Set_021f7864(struct Obj28_021f7864* obj) {
	if (obj->flags & 1) return;
	ClearBuffer0204b010((struct Obj0204b010*)((char*)obj + 0x28), NULL);
}
