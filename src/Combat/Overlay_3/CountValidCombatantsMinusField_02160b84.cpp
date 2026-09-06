#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantChecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov003_02160b84
ARM int CountValidCombatantsMinusField_02160b84(void) {
	struct BattleStruct* bs = GetBattleStruct();
	int count = 0;
	int i;
	for (i = 0; i < 4; i++) {
		if (GetCombatantChecked(bs, i) != 0) count++;
	}
	return count - *((unsigned char*)GetPtrField0x2a04(GetBattleStruct()) + 0xf7c);
}
