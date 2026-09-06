#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int IsField0Null(void** obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
void Something_021a6b9c(int unused0, unsigned char byteVal);

// USA: func_ov017_021d1d00  (semantic: CheckProximityAndEnqueue_021d1d00)
extern "C" ARM void func_ov017_021d1d00(int unused0, int unused1, struct BattleStruct* battleStruct, unsigned char* ov, struct SearchStruct0202c1a4* search) {
    if (!GetSearchStructCurrentArrEntry(search)) return;
    void** list = *(void***)(ov + 0x3000 + 0x6fc);
    if (!IsField0Null(list)) return;

    struct CombatantStruct* c1 = GetCombatantWithFlag0x800(battleStruct, 0);
    struct CombatantStruct* c2 = GetCombatantAtField0x397c(battleStruct);
    if (!c1 || !c2) return;
    if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c1) != _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c2)) return;

    struct Vec3s32_020c3030 v1 = *(struct Vec3s32_020c3030*)((char*)c1 + 0x44);
    struct Vec3s32_020c3030 v2 = *(struct Vec3s32_020c3030*)((char*)c2 + 0x44);
    if (Vector3fix_Distance(&v1, &v2) >= 0x7800) return;
    Something_021a6b9c((int)ov, 0);
}
