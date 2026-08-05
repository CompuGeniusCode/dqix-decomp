#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3_02073dfc { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" struct Vec3_02073dfc func_02034104(struct CombatantStruct* combatant);
void CopyVec3(int* dst, int* src);
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

// USA: func_02073dfc
extern "C" ARM int func_02073dfc(unsigned short* idPtr, struct Vec3s32_020c3030* distArg) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant;
    for (int i = 0; i < 4; i++) {
        combatant = GetCombatantWithFlag0x800(battleStruct, i);
        if (combatant == 0) continue;
        int targetId = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
        struct Vec3_02073dfc local = func_02034104(combatant);
        if (*(int*)((char*)combatant + 0x15c) != -1) {
            targetId = *(int*)((char*)combatant + 0x15c);
            if (i == 0 || (combatant->flags & 0x1000)) {
                CopyVec3((int*)&local, (int*)((char*)combatant + 0x160));
            }
        }
        if (*idPtr == targetId) {
            int dist = Distance3D020c3030(distArg, (struct Vec3s32_020c3030*)&local);
            if (dist < 0x3800) {
                return 1;
            }
        }
    }
    return 0;
}
