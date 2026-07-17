#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);
int GetSignedByte0x2d1(void* obj);

#pragma optimize_for_size off
// USA: func_ov017_02191764
ARM int FindUnusedSlot_02191764(int a, int b) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	int bitmask = 0;
	for (int i = 0; i < 4; i++) {
		struct CombatantStruct* combatant = GetCombatantWithFlag0x1000(battleStruct, i);
		if (!combatant || i == a) continue;
		if (b != GetSignedByte0x2d0(combatant)) continue;
		bitmask |= 1 << GetSignedByte0x2d1(combatant);
	}
	int result = 0;
	for (int j = 0; j < 4; ++j) {
		if ((bitmask & (1 << j)) == 0) {
			result = j;
			break;
		}
	}
	return result;
}
