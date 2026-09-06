#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" void* func_02012fe4(void);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

extern "C" int func_02030f30(int angle);
extern "C" int func_02030c68(int angle);
extern "C" int func_02030c9c(int angle);

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int fix32_Atan2(int x, int z);
extern "C" int Vector3fix_Length(int* v);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);
struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
void SetBothCounters(void* obj, int value, int frames);
int CheckField0x14Or0x20Positive(int* obj);

extern "C" unsigned char _Z19CopyOutRegion0x5718PcPv(void* src, void* dst);
#define CopyOutRegion0x5718 _Z19CopyOutRegion0x5718PcPv
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

void* GetField0x3f8Address(struct BattleStruct* battleStruct);
int GetField0x3acValue(struct BattleStruct* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _Z28CallFunc0200fbb4AtField0x3f8Pv(void* battle, void* obj);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct PosData_021ab280 {
    char pad0[8];
    int x, y, z;               // 0x8, 0xc, 0x10
    char pad1[0x20 - 0x14];
    short angle;                 // 0x20
    char pad2[0x30 - 0x22];
    unsigned short half30;        // 0x30
    char pad3[0x38 - 0x32];
    struct Vec3 vecArr[4];         // 0x38, 0x44, 0x50, 0x5c
    short half68;                   // 0x68
    short half6a;                    // 0x6a
};

struct Obj_021ab280 {
    char pad0[1];
    unsigned char field1;        // 0x1
    char pad1[8 - 2];
    int state;                     // 0x8
    int counter;                    // 0xc
    struct PosData_021ab280* pos;    // 0x10
    struct Vec3 vec14;                // 0x14
};

// USA: func_ov017_021ab280
extern "C" ARM int func_ov017_021ab280(struct Obj_021ab280* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    func_0202ae18();
    unsigned char* mgr = (unsigned char*)func_ov017_0218b5b0();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    void* g = func_02012fe4();

    int state = obj->state;
    if (state == 0) {
        CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
        _ZN8Object3D10EnableFlagEi((unsigned char*)combatant, 0x01000080);

        struct Vec3 dir;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        int angleY = func_02030f30(obj->pos->angle + (int)0xffffcdc3);
        dir.x = func_02030c68(angleY);
        dir.y = 0;
        dir.z = func_02030c9c(angleY);
        Vector3fix_Normalize(&dir, &dir);
        Vector3fix_Add((struct Vec3*)&obj->pos->x, &dir, &obj->vec14);
        Vector3fix_Subtract(&obj->vec14, &saved, &dir);
        Vector3fix_Normalize(&dir, &dir);
        int angle2 = fix32_Atan2(dir.x, dir.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 1);
        SetBothCounters(mgr, -16, 15);

        obj->state = obj->state + 1;
        obj->counter = 0;
    } else if (state == 1) {
        int gVal = *((unsigned char*)g + 0x830);
        if (gVal <= 4) {
            obj->state = state + 1;
            obj->counter = 0;
            SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        }
    } else if (state == 2) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract(&obj->vec14, &saved, &delta);
        Vector3fix_Length((int*)&delta);
        Vector3fix_Subtract(&obj->vec14, &saved, &delta);
        Vector3fix_Normalize(&delta, &delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (CheckField0x14Or0x20Positive((int*)mgr) == 0) {
            obj->state = 4;
            obj->counter = 0;
        }
    } else if (state == 3) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract(&obj->vec14, &saved, &delta);
        Vector3fix_Normalize(&delta, &delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (CheckField0x14Or0x20Positive((int*)mgr) == 0) {
            obj->state = obj->state + 1;
            obj->counter = 0;
        }
    } else if (state == 4) {
        _ZN8Object3D11DisableFlagEi((unsigned char*)combatant, 0x01000080);

        unsigned char buf[4];
        unsigned char count = CopyOutRegion0x5718((void*)battle, buf);
        for (int i = 0; i < count; i++) {
            struct CombatantStruct* c = GetCombatantUnchecked(battle, buf[i]);
            if (c != 0) {
                _ZN8Object3D11DisableFlagEi((unsigned char*)c, 0x1000000);
            }
        }

        void* entryV = GetField0x3f8Address(battle);
        GetField0x3acValue(battle);
        VectorizedMemset(entryV, 0, 0x70);
        unsigned char* e = (unsigned char*)entryV;
        unsigned char one = 1;
        e[4] = one;
        e[8] = one;
        e[9] = one;
        int negOneB = one - 2;
        *(signed char*)(e + 0xb) = negOneB;
        *(int*)(e + 0x20) = negOneB;
        *(int*)(e + 0x24) = negOneB;
        *(int*)(e + 0x28) = negOneB;
        *(int*)(e + 0x2c) = negOneB;
        *(short*)(e + 0x1e) = negOneB;
        e[0xc] = 0;
        *(short*)(e + 0x6c) = negOneB;

        *(unsigned short*)(e + 0) = obj->pos->half30;
        _ZN8Vector3iaSERKS_((int*)(e + 0x10), (int*)&obj->pos->vecArr[0]);
        *(short*)(e + 0x1c) = obj->pos->half68;
        e[0xb] = (unsigned char)obj->pos->half6a;
        _ZN8Vector3iaSERKS_((int*)(e + 0x30), (int*)&obj->pos->vecArr[0]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x3c), (int*)&obj->pos->vecArr[1]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x48), (int*)&obj->pos->vecArr[2]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x54), (int*)&obj->pos->vecArr[3]);

        e[0xc] = 1;
        e[7] = 1;
        _Z28CallFunc0200fbb4AtField0x3f8Pv(battle, entryV);

        InitAndResetHeader_0219e310(*(unsigned char**)(mgr + 0x3000 + 0x70c), 0);
        AppendNodeToTail(*(struct TailList020469b4**)(mgr + 0x3000 + 0x6fc),
                          *(struct TailNode020469b4**)(mgr + 0x3000 + 0x70c));

        obj->field1 = 1;
    }

    obj->counter = obj->counter + 1;
    return obj->counter;
}
