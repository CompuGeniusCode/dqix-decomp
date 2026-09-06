#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct Vec3_0202445c { int x; int y; int z; };

struct Obj0202445c {
    char pad0[0x14];
    int mode;
    char pad1[0x20];
    int range;
    char pad2[0x570];
    int posX;
    int posZ;
};

// USA: func_0202445c  (semantic: SyncPositionFromCombatant0202445c)
extern "C" ARM void func_0202445c(struct Obj0202445c* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (battleStruct == 0) return;
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    if (combatant == 0) return;

    struct Vec3_0202445c* pos = (struct Vec3_0202445c*)((char*)combatant + 0x44);
    obj->posX = pos->x;
    obj->posZ = pos->z;

    if (obj->mode == 3) {
        int a = fix32_Divide(0x37000, obj->range);
        int b = fix32_Divide(0x1e000, obj->range);
        if (obj->posZ < 0) {
            if (obj->posZ < -a) {
                obj->posZ = -(a + obj->posZ);
            } else {
                obj->posZ = 0;
            }
        } else if (obj->posZ > 0) {
            if (obj->posZ > b) {
                obj->posZ = obj->posZ - b;
            } else {
                obj->posZ = 0;
            }
        } else {
            obj->posZ = 0;
        }
    } else if (obj->mode == 4) {
        obj->posZ = pos->y;
    }
}
