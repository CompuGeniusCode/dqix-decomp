#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(struct Obj02053f7c* obj, short a, int b);

// USA: func_ov017_021c98f4
ARM void SetFieldForMatchingCombatant_021c98f4(int target, int flag) {
	struct BattleStruct* bs = GetBattleStruct();
	int i;
	for (i = 0; i < 4; i++) {
		struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, i);
		if (!c) {
			continue;
		}
		unsigned short val = *(unsigned short*)((char*)c + 0x1b2);
		if (target != val) {
			continue;
		}
		SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c, 0, flag);
	}
}
