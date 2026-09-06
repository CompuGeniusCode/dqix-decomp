#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021bd440
ARM void ClearFlagAndZeroVec3Field_021bd440(void* self, int index) {
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	int wasSet = 0;
	if (base[0x174] & mask) wasSet = 1;
	base[0x174] &= ~mask;
	base[0x175] |= mask;
	if (!wasSet) return;
	struct CombatantStruct* combatant = GetCombatantWithFlag0x800(GetBattleStruct(), index);
	if (!combatant) return;
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x188 + index * 0xc));
	int value = *(int*)(base + 0x1b8 + index * 4);
	*(int*)((char*)combatant + 0x50) = 0;
	*(int*)((char*)combatant + 0x54) = value;
	*(int*)((char*)combatant + 0x58) = 0;
}
