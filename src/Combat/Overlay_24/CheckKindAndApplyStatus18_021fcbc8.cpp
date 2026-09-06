#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(void* obj, int idx);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int zero, int val);
int IsCombatantFlag2Mask512_021eadfc(struct CombatantStruct* combatant);

struct Obj_021fcbc8 {
	char pad0[4];
	short field4;
	unsigned char kind;
	char pad7;
	struct CombatantStruct* combatant;
	int field0xc;
};

// USA: func_ov024_021fcbc8  (semantic: CheckKindAndApplyStatus18_021fcbc8)
extern "C" ARM void func_ov024_021fcbc8(struct Obj_021fcbc8* obj) {
	int trigger = 0;
	if (obj->kind == 2) trigger = 1;
	if (obj->kind == 0) return;
	if (obj->field0xc >= 3) trigger = 1;
	if (!trigger) return;
	if (!func_ov024_021fe698(obj, 0x12)) return;
	if (obj->field0xc <= 1) return;
	if (IsCombatantFlag2Mask512_021eadfc(obj->combatant)) return;
	char buf[0xc8];
	memset(buf, 0, 0xc8);
	*(float*)(buf + 0xc4) = 1000.0f;
	func_ov024_021f9874(obj, buf, 0, (unsigned char)obj->field4);
}
