#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

// USA: func_ov024_021f5300
ARM int SetFlagIfStatByteBelow3_021f5300(int* a0, int a1, int a2, int* a3, short* a4) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!c) return 0;
	if (((unsigned char*)c->currentStats)[0x24] >= 3) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
