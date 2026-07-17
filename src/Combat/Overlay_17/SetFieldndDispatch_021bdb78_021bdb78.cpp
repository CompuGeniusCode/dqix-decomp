#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
int CallHelperIfCheckPasses_0218fcf8(int a, int b, int c);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021bdb78
ARM void SetFieldndDispatch_021bdb78_021bdb78(int id) {
	struct BattleStruct* bs = GetBattleStruct();
	int helper = func_ov017_0218b5b0();
	struct CombatantStruct* combatant = GetCombatantUnchecked(bs, id);
	if (!combatant) {
		return;
	}
	*(short*)((char*)combatant + 0x9c) = 0x40c8;
	CallHelperIfCheckPasses_0218fcf8(helper, 0, 0x40c8);
}
