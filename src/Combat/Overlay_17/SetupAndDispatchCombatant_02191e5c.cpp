#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantFromList(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
extern "C" void _ZN8Object3D10SetField9eEh(unsigned char* obj, unsigned char value);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);

void SetGroupShortValues_021919c8(int unusedA, int b, short c);
extern "C" void func_ov017_0218fd34(int a, int b, unsigned short e);
extern "C" void func_ov017_0218f968(int a, int b, unsigned short e);

// USA: func_ov017_02191e5c
ARM void SetupAndDispatchCombatant_02191e5c(int a, int b, short c, unsigned char d, unsigned short e) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	int inRange1 = (b >= 0 && b <= 3);
	if (inRange1) {
		if (!GetCombatantWithFlag0x800(battleStruct, b)) return;
	}
	struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, b);
	if (!combatant) return;
	SetGroupShortValues_021919c8(a, b, c);
	*(unsigned short*)((char*)combatant + 0x9c) = e;
	_ZN8Object3D10SetField9eEh((unsigned char*)combatant, d);
	int inRange2 = (b >= 0 && b <= 3);
	if (inRange2) {
		struct CombatantStruct* c2 = GetCombatantWithFlag0x100(battleStruct, b);
		if (!c2) return;
		if (!CheckField0x56bLowNibble((struct Obj02061bd8*)c2)) {
			func_ov017_0218fd34(a, b, e);
			return;
		}
	}
	func_ov017_0218f968(a, b, e);
}
