#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_02034d20(void* obj);
extern "C" void func_02035a2c(void* p, int flag);

// USA: func_ov003_02154f80  (semantic: UpdateVecFromCombatant_02154f80)
extern "C" ARM void func_ov003_02154f80(char* obj) {
    if (*(int*)(obj + 0x32c) == 0) return;
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, *(signed char*)(obj + 0x1f7));
    if (combatant != 0) {
        CopyVec3ToField0x44((struct Target02059f38*)(obj + 0x280), (struct Vec3_02059f38*)((char*)combatant + 0x44));
    }
    func_02034d20(obj + 0x280);
    func_02035a2c(obj + 0x280, 1);
}
