#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* FindCombatantByField16a_021a278c(void* unused, int val);
extern "C" void func_02076a8c(void* c);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);

// USA: func_ov017_021a23b0  (semantic: MaybeSetFlag6cForCombatant_021a23b0)
extern "C" ARM void func_ov017_021a23b0(void* self, int val) {
	GetBattleStruct();
	struct CombatantStruct* c = FindCombatantByField16a_021a278c(self, val);
	if (!c) return;
	func_02076a8c(c);
	_ZN8Object3D10MakeHiddenEv((unsigned char*)c);
}
