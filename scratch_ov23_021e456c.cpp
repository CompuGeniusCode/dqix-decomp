#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov023_021e6194(void* p);
extern "C" void func_02036e34(void* obj, int v, int flag);
struct S1a0_021e456c { char pad[0x1c]; unsigned int f1c; unsigned int f20; };
extern "C" void ShiftField0x1cInto0x20(struct S1a0_021e456c* obj, unsigned int v);
extern "C" int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_ov023_021e5974(void* a, int b, int c, int d, int e);

struct Obj_021e456c {
	char pad0[0x128];
	void* f128;
	void* f12c;
	char pad0b[4];
	int f134;
	char pad1[0x3c4];
	int f4fc;
	char pad2[0x134];
	unsigned short f634;
};

// USA: func_ov023_021e456c
ARM void SyncCombatantWordFields_021e456c(struct Obj_021e456c* obj) {
	if (!(obj->f634 & 4)) return;
	struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), obj->f4fc);
	if (!combatant) return;
	int flag = 0;
	if (obj->f634 & 0x10) flag = 1;
	void* r6 = func_ov023_021e6194(obj->f128);
	void* r5 = func_ov023_021e6194(obj->f12c);
	func_02036e34(r5, *(int*)((char*)r6 + 0x14), 0);
	ShiftField0x1cInto0x20((struct S1a0_021e456c*)r5, *(unsigned int*)((char*)r6 + 0x1c));
	func_ov023_021e5974(obj->f12c, GetFieldAt0x150((unsigned char*)combatant), obj->f4fc, flag, 1);
	obj->f634 &= ~4;
	obj->f634 &= ~0x10;
	obj->f134 = 0;
	obj->f634 |= 8;
}
