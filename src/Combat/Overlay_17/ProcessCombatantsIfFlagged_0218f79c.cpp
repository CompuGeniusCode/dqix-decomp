#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov017_02191fec(void* obj, int idx);
extern "C" void func_ov017_0218f80c(void* obj, int idx);

// USA: func_ov017_0218f79c
ARM void ProcessCombatantsIfFlagged_0218f79c(void* obj) {
	struct BattleStruct* battle = GetBattleStruct();
	int i;
	for (i = 0; i < 4; i++) {
		if (GetCombatantUnchecked(battle, i) != NULL) {
			int flag = func_ov017_02191fec(obj, i) ? 1 : 0;
			if (flag) {
				func_ov017_0218f80c(obj, i);
			}
		}
	}
}
