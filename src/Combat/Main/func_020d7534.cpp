#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct IntField0x68_020377bc;
extern "C" int _ZNK8Object3D9GetHeightEv(struct IntField0x68_020377bc* obj);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec3_020d7534 { int x; int y; int z; };
extern "C" void func_020d74a4(void* base, int index, struct Vec3_020d7534 v);

void AdvanceActorCooldownsAndPosition0205a020(unsigned char* p, int dt);

struct Actor020d7534 {
    char pad0[0x50];
    struct Vec3_020d7534 pos;
    char pad1[0x74];
    int fieldD0;
    char pad2[4];
};

// USA: func_020d7534
extern "C" ARM void func_020d7534(struct Actor020d7534* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned int scaleCount = GetBattleScaleCount(battle);
    int i;
    for (i = 0; i < 0xc; i++) {
        unsigned short flags = *(unsigned short*)((char*)obj + 0xa24);
        if (flags & (1 << i)) {
            int id = i;
            if (i > 3) {
                id = i + 0xbc;
            }
            struct CombatantStruct* combatant = GetCombatantUnchecked(battle, id);
            if (combatant != 0) {
                struct Vec3_020d7534 v = *(struct Vec3_020d7534*)((char*)combatant + 0x84);
                v.y = _ZNK8Object3D9GetHeightEv((struct IntField0x68_020377bc*)combatant);
                func_020d74a4(obj, i, v);

                if (obj[i].fieldD0 == 4) {
                    struct Actor020d7534* actor = &obj[i];
                    int limit = 0x6488;
                    struct Vec3_020d7534 tmp = actor->pos;
                    tmp.y = tmp.y + 0x66 + 0x200;
                    if (tmp.y > limit) {
                        tmp.y = tmp.y - limit;
                    }
                    _ZN8Vector3iaSERKS_((int*)&actor->pos, (int*)&tmp);
                }
                AdvanceActorCooldownsAndPosition0205a020((unsigned char*)&obj[i], scaleCount);
            }
        }
    }
}
