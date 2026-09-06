#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct020372b8;
struct S02037418;
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);
struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov023_021ed988
ARM void ScaleOrResetCombatants_021ed988(char *obj, int brightness) {
	struct BattleStruct *bs = GetBattleStruct();
	for (int i = 0; i < *(unsigned char*)(obj + 0x6000 + 0xe2e); i++) {
		unsigned short *idxPtr = (unsigned short*)(obj + i * 2 + 0x6e00 + 0x30);
		struct CombatantStruct *combatant = GetCombatantWithFlag0x400(bs, *idxPtr);
		if (brightness > 0) {
			_ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)combatant, 0, brightness);
		} else {
			_ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)combatant, 0);
		}
	}
}
