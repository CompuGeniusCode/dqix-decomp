#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

// USA: func_ov024_021f2d4c  (semantic: CheckMagicalMendingBuffBelow2_021f2d4c)
extern "C" ARM int func_ov024_021f2d4c(int* p0, short id, int unused2, int* outFlag, short* out5) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*p0, id);
	if (!c) return 0;
	if (c->currentStats->magicalMendingBuff >= 2) {
		return 0;
	} else {
		*out5 = id;
		*outFlag = 1;
		return 1;
	}
}
