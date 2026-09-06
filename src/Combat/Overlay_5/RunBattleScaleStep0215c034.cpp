#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

extern "C" void func_ov005_02158e04(void *combatant, unsigned int scaleCount);

// USA: func_ov005_0215c034
ARM void RunBattleScaleStep0215c034(void *combatant) {
	unsigned int scaleCount = GetBattleScaleCount(GetBattleStruct());
	if (scaleCount == 0) scaleCount = 1;
	func_ov005_02158e04(combatant, scaleCount);
}
