#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Obj02039d84;
extern void ResetObjectState02039d84(struct Obj02039d84* obj);

// USA: func_ov017_021d443c
ARM void MaybeResetCombatantById_021d443c(int a, signed char* b, struct BattleStruct* battle) {
	int id = a;
	signed char v = b[4];
	if (v != -1) {
		id = v;
	}
	struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, id);
	if (c) {
		ResetObjectState02039d84((struct Obj02039d84*)c);
	}
}
