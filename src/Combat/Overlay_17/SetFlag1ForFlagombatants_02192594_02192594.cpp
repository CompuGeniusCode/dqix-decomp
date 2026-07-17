#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(struct Obj02053f7c* obj, short a, int b);

// USA: func_ov017_02192594
ARM void SetFlag1ForFlagombatants_02192594_02192594(void) {
	struct BattleStruct* bs = GetBattleStruct();
	int i;
	for (i = 0; i < 4; i++) {
		struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, i);
		if (c) {
			SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c, 0, 1);
		}
	}
}
