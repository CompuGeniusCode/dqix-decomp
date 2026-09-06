#include <globaldefs.h>

struct BattleStruct;
void* GetCombatantWithFlag0x800(BattleStruct* battleStruct, int combatantId);

struct S021d25b8 { unsigned char pad0[4]; unsigned char field4; unsigned char pad1[3]; int field8; };

// USA: func_ov017_021d25b8
ARM void SetCombatantFlag8IfField8_021d25b8(int unused, S021d25b8* obj, BattleStruct* battleStruct) {
	void* combatant = GetCombatantWithFlag0x800(battleStruct, obj->field4);
	if (!combatant) return;
	unsigned int* flags = (unsigned int*)((char*)combatant + 0x18c);
	if (obj->field8 != 0) *flags |= 8;
	else *flags &= ~8;
}
