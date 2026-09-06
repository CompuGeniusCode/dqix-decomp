#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct BattleStruct* GetBattleStruct(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);
void SetFlag0x1ceBit0x4(unsigned char* obj);

struct Src021d2c78 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
};

// USA: func_ov017_021d2c78
ARM void NotifyFlag2048AndMaybeSet_021d2c78(void* unused, Src021d2c78* src) {
	struct BattleStruct* bs = GetBattleStruct();
	struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, src->field4);
	if (c == NULL) return;

	_ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)c, src->field5);
	if (src->field5 != 0) return;
	if (src->field6 == 0) return;

	SetFlag0x1ceBit0x4((unsigned char*)c);
}
