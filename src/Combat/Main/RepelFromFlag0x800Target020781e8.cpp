#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct Vec3 {
    int x;
    int y;
    int z;
};
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

extern "C" struct Vec3 func_02034104(struct CombatantStruct* combatant);
extern "C" void Vector3fix_Normalize(struct Vec3* out, struct Vec3* in);
extern "C" int fix32_Atan2(int x);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};
extern "C" void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c927c(int a, int b, int c, struct Vec3 v, int d, int e, int f);

struct Entity020781e8 {
    char pad0[0x2];
    short f2;
    short f4;
    char pad1[0x3e];
    struct Vec3 f44;
    char pad2[0x62];
    short fb2;
    short fb4;
    char pad3[0xa2];
    struct Vec3 f158;
    char pad4[0x2];
    unsigned short f166;
    char pad5[0x12];
    unsigned char f17a;
};

// USA: func_020781e8
ARM int RepelFromFlag0x800Target020781e8(struct Entity020781e8* e) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, e->f166);
    if (combatant == NULL) {
        return 0;
    }

    int scale = 0;
    void* g = func_0202ae18();
    if (!CheckField0NonZero((int*)g) || GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
        struct Vec3 posCopy = func_02034104(combatant);
        struct Vec3 delta;
        Vector3fix_Subtract(&posCopy, &e->f44, &delta);
        Vector3fix_Normalize(&delta, &delta);
        delta.x = -delta.x;
        delta.y = -delta.y;
        delta.z = -delta.z;
        scale = fix32_Atan2(delta.x);
        SetVecYByMode02033834((struct Obj02033834*)e, scale);
        delta.y = 0;
        func_02030e2c((struct Vec3Fixed02030e2c*)&delta, 0x5000, (struct Vec3Fixed02030e2c*)&delta);
        Vector3fix_Add(&e->f44, &delta, &e->f158);
    }

    e->fb4 = 0x1c2;
    e->fb2 = 0x1c2;
    SetByteIfChanged02033b68((struct Obj02033b68*)e, 1);
    _ZN8Object3D11DisableFlagEi((unsigned char*)e, 0x80);
    e->f17a = 0;

    if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)e);
        int f2val = e->f2;
        struct Vec3* vp = &e->f158;
        int rem = (e->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            struct Vec3 v = *vp;
            func_ov017_021c927c(c1, rem, f2val, v, scale, 7, e->f166);
        }
    }
    return 1;
}
