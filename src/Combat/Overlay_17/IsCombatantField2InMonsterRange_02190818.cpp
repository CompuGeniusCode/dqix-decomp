#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_02190818
ARM int IsCombatantField2InMonsterRange_02190818(int id) {
	struct BattleStruct* bs = GetBattleStruct();
	if (GetCombatantWithFlag0x800(bs, id) == NULL)
		goto zero;
	{
	struct CombatantStruct* c = GetCombatantUnchecked(bs, id * 0xc + 0x14);
	if (c == NULL)
		goto zero;
	{
	short v = *(short*)((char*)c + 2);
	if (v != 0x2347) {
		if (v != 0x2348) {
			if (v != 0x2349) {
				goto zero;
			}
		}
	}
	return 1;
	}
	}
zero:
	return 0;
}
