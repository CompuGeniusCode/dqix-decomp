#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

// USA: func_ov024_021f59c4
ARM int SetFlagIfStatShort2Zero_021f59c4(int* a0, int a1, int a2, int* a3, short* a4) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!c) return 0;
	if (*(unsigned short*)((unsigned char*)c->currentStats + 2) != 0) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
