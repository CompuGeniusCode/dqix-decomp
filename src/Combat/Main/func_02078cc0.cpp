#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);

extern "C" struct Vec3 func_02034104(struct CombatantStruct* combatant);
extern "C" void Vector3fix_Normalize(struct Vec3* out, struct Vec3* in);
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);

extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);

struct ShortPair0xba0xbc;
void SetFields0xbaAnd0xbc(struct ShortPair0xba0xbc* obj, short a, short b);

struct Entity02078cc0 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad50[0xb0 - 0x50];
    unsigned short fb0;
    unsigned short fb2;
    char padb4[0x166 - 0xb4];
    unsigned short f166;
    char pad168[0x17a - 0x168];
    unsigned char f17a;
};

// USA: func_02078cc0  (semantic: AimAtFlagTargetOrReset_02078cc0)
extern "C" ARM int func_02078cc0(struct Entity02078cc0* self) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, self->f166);
    if (combatant == 0) {
        return 0;
    }
    SetByteSavingPrevious((struct Foo02033b58*)self, 0);
    self->fb0 = 0x328;
    self->fb2 = 0;
    struct Vec3 posCopy = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract(&posCopy, &self->f44, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    SetVecYByMode02033834((struct Obj02033834*)self, angle);
    _ZN8Object3D10EnableFlagEi((unsigned char*)self, 0x80);
    SetFields0xbaAnd0xbc((struct ShortPair0xba0xbc*)self, 0xcc, 0xaf0);
    self->f17a = 0;
    return 1;
}
