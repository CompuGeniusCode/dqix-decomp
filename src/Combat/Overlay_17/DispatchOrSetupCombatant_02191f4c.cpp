#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantFromList(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void SetFieldndDispatch_021bdb78_021bdb78(int id);
void SetupAndDispatchCombatant_02191e5c(int a, int b, short c, unsigned char d, unsigned short e);

extern "C" void func_ov017_0218f80c(int a, int b);

// USA: func_ov017_02191f4c
ARM void DispatchOrSetupCombatant_02191f4c(int a, int b) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, b);
	if (!combatant) return;
	struct CombatantStruct* c2 = GetCombatantWithFlag0x100(battleStruct, b);
	if (c2 != NULL && (*(int*)((char*)c2 + 0x18c) & 0x40)) {
		SetFieldndDispatch_021bdb78_021bdb78(b);
		return;
	}
	SetupAndDispatchCombatant_02191e5c(a, b, 0x1000, 0, 0);
	int inRange = (b >= 0 && b <= 3);
	if (inRange) {
		func_ov017_0218f80c(a, b);
	}
}
