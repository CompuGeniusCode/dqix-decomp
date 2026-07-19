#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* FindCombatantByField16a_021a278c(void* unused, int val);
extern "C" void func_02076a8c(void* c);
void SetFlag0x6cBit0(unsigned char* obj);

// USA: func_ov017_021a23b0  (semantic: MaybeSetFlag6cForCombatant_021a23b0)
extern "C" ARM void func_ov017_021a23b0(void* self, int val) {
	GetBattleStruct();
	struct CombatantStruct* c = FindCombatantByField16a_021a278c(self, val);
	if (!c) return;
	func_02076a8c(c);
	SetFlag0x6cBit0((unsigned char*)c);
}
