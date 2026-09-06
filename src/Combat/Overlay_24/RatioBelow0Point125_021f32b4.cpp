#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

struct Sub_021f32b4 { char pad[2]; unsigned short field2; unsigned short field4; unsigned short field6; };

// USA: func_ov024_021f32b4  (semantic: RatioBelow0Point125_021f32b4)
extern "C" ARM int func_ov024_021f32b4(int* a0, int a1, int a2, int* a3, short* a4) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!c) return 0;
	volatile struct Sub_021f32b4* sub = (volatile struct Sub_021f32b4*)c->currentStats;
	unsigned short f6 = sub->field6;
	unsigned short f2 = sub->field2;
	float ratio = (float)f2 / (float)f6;
	if (ratio > 0.125f) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
