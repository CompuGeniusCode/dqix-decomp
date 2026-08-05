#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);

struct Vec3 {
    int x;
    int y;
    int z;
};
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

extern "C" struct Vec3 func_02034104(struct CombatantStruct* combatant);
extern "C" void func_020c2f18(struct Vec3* out, struct Vec3* in);
extern "C" int func_020c338c(int x, int z);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);

struct Entity02078688 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad1[0x62];
    short fb2;
    char pad2[0xb2];
    unsigned short f166;
    char pad3[0x12];
    unsigned char f17a;
};

// USA: func_02078688  (semantic: AimAtFlagTargetAndReset02078688)
extern "C" ARM int func_02078688(struct Entity02078688* self) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x2(battleStruct, self->f166);
    if (combatant != 0) {
        struct Vec3 posCopy = func_02034104(combatant);
        struct Vec3 delta;
        SubtractVec3(&posCopy, &self->f44, &delta);
        func_020c2f18(&delta, &delta);
        int angle = func_020c338c(delta.x, delta.z);
        SetVecYByMode02033834((struct Obj02033834*)self, angle);
    }

    self->fb2 = 0;
    SetByteIfChanged02033b68((struct Obj02033b68*)self, 2);
    SetBitsInField0x6c((unsigned char*)self, 0x80);
    self->f17a = 0;
    return 1;
}
