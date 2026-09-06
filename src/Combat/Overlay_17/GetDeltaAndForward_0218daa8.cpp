#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3 { int x; int y; int z; };
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int func_ov017_0218db14(void* obj, int* vec, int c, int d, unsigned char e);

// USA: func_ov017_0218daa8
ARM int GetDeltaAndForward_0218daa8(void* obj, struct Vec3* otherVec, int c, int d, unsigned char e) {
	struct Vec3 diff;
	struct CombatantStruct* combatant = GetCombatantAtField0x397c(GetBattleStruct());
	if (!otherVec) return 0;
	if (!combatant) return 0;
	Vector3fix_Subtract((struct Vec3*)((char*)combatant + 0x44), otherVec, &diff);
	return func_ov017_0218db14(obj, (int*)&diff, c, d, e);
}
