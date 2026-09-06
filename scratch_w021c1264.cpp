#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_02191fec(int h, int combatantId);

// USA: func_ov017_021c1264
ARM void SomeFunc_021c1264(void) {
	struct BattleStruct* battle = GetBattleStruct();
	int h = func_ov017_0218b5b0();
	for (int i = 0; i < 4; i++) {
		if (GetCombatantWithFlag0x800(battle, i) != NULL) {
			func_ov017_02191fec(h, i);
		}
	}
}
