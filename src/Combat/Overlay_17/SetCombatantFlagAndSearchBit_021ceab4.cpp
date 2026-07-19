#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SearchStruct;

struct BattleStruct* GetBattleStruct(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void SetFlag0x1ceBit0x10(unsigned char* obj);
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);

// USA: func_ov017_021ceab4
ARM void SetCombatantFlagAndSearchBit_021ceab4(int combatantId, int unused1, int unused2, int unused3, struct SearchStruct* search) {
	struct CombatantStruct* combatant = GetCombatantWithFlag0x800(GetBattleStruct(), combatantId);
	if (combatant != NULL) {
		SetFlag0x1ceBit0x10((unsigned char*)combatant);
	}
	SetSearchFlagBit0202c660(search, combatantId);
}
