#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* FindCombatantByField16a_021a278c(void* unused, int val);
extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov017_021c5a1c
ARM int IsValidCombatantValue_021c5a1c(int val) {
	if (val < 0x8000)
		goto skip;
	if (val <= 0x8004)
		return 1;
skip:
	if (val < 1)
		return 0;
	if (val > 0x7fff)
		return 0;
	GetBattleStruct();
	void* p = func_ov017_0218b5b0();
	if (p == NULL)
		return 0;
	return FindCombatantByField16a_021a278c(p, val) != NULL;
}
