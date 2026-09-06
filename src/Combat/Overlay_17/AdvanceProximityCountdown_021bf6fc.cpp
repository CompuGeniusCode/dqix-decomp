#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct S_377d4;
extern "C" int _ZNK8Object3D25IsTransitioningAnimationsEv(struct S_377d4* obj);
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);
struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

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
	int dist = Vector3fix_Distance(&pos, &refPos);
	*(short*)(obj + 0x14) -= 1;
	if (dist < 0x199 || (*(short*)(obj + 0x14) < 0 && !_ZNK8Object3D25IsTransitioningAnimationsEv((struct S_377d4*)combatant))) {
		SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 0);
		*(short*)(obj + 0x14) = -1;
		return 2;
	}
	return 1;
}
