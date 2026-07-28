#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct S_377d4;
int CheckField0x38NonZero(struct S_377d4* obj);
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);
struct Vec3s32_020c3030 { int x; int y; int z; };
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_021bf6fc  (semantic: AdvanceProximityCountdown_021bf6fc)
extern "C" ARM int func_ov017_021bf6fc(unsigned char* obj) {
	struct BattleStruct* battle = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
	unsigned char* target = *(unsigned char**)(obj + 0xc);
	struct Vec3s32_020c3030 pos = *(struct Vec3s32_020c3030*)((char*)combatant + 0x44);
	struct Vec3s32_020c3030 refPos;
	refPos.x = *(int*)(target + 0x8);
	refPos.y = pos.y;
	refPos.z = *(int*)(target + 0x10);
	int dist = Distance3D020c3030(&pos, &refPos);
	*(short*)(obj + 0x14) -= 1;
	if (dist < 0x199 || (*(short*)(obj + 0x14) < 0 && !CheckField0x38NonZero((struct S_377d4*)combatant))) {
		SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 0);
		*(short*)(obj + 0x14) = -1;
		return 2;
	}
	return 1;
}
