#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void CopyVec3(int* dst, int* src);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021bd3d4
ARM void SetFlagAndSyncVec3_021bd3d4(void* self, int index) {
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	base[0x174] |= mask;
	base[0x175] &= ~mask;
	struct CombatantStruct* combatant = GetCombatantWithFlag0x800(GetBattleStruct(), index);
	if (combatant) {
		CopyVec3((int*)(base + 0x188 + index * 0xc), (int*)((char*)combatant + 0x44));
		*(int*)(base + 0x1b8 + index * 4) = *(int*)((char*)combatant + 0x54);
	}
}
