#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

// USA: func_ov024_021f5428  (semantic: CheckStatCodeField48_021f5428)
extern "C" ARM int func_ov024_021f5428(int* p0, short id, int unused2, int* outFlag, short* out5) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*p0, id);
	if (!c) return 0;
	unsigned short field = *(unsigned short*)((char*)c->currentStats + 0x30);
	if (field != 0x1c && field != 0x247) {
		return 0;
	} else {
		*outFlag = 1;
		*out5 = id;
		return 1;
	}
}
