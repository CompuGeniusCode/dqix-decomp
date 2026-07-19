#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Overlay_17/Struct44C8.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_0218f5a4(void* ov, int id, int b, int c, int d);

// USA: func_ov017_021b0b4c
ARM int CheckCombatantsAndBit4_021b0b4c(void) {
	struct BattleStruct* bs = GetBattleStruct();
	Struct_ov017_44C8* ov = func_ov017_0218b5b0();

	int i;
	for (i = 0; i < 4; i++) {
		struct CombatantStruct* combatant = GetCombatantUnchecked(bs, i);
		if (combatant) {
			func_ov017_0218f5a4(ov, i, 0, 0, 0);
		}
	}

	return GetBitsInField0((unsigned int*)ov, 0x10) == 0 ? 1 : 0;
}
