#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3_021e75a4 { int x; int y; int z; };
struct Vec3;
struct Vec3_02030ef0;

extern "C" void* __clear(void* dst, int count);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(struct Vec3_02030ef0* src, unsigned int a, struct Vec3_02030ef0* dst);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void ResetFields_021de110(void* obj);
struct Obj021eee48;
struct Rec021eee48;
void PushNodeFromFreeList_021eee48(struct Obj021eee48* obj, struct Rec021eee48* src);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern char data_ov025_021ef834[];

struct Entry021e75a4 {
    int f0;
    int f4;
    short id;
    short val;
    int rel[3];
    void* next;
};

// USA: func_ov025_021e75a4  (semantic: RebaseAndQueueCombatantPositions_021e75a4)
extern "C" ARM int func_ov025_021e75a4(void* unused0, void* unused1, struct Obj021eee48* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    void* arr[8];
    int validCount;
    void** slot;
    int i;

    slot = arr;
    validCount = 0;
    struct Vec3_021e75a4 accum;
    __clear(&accum, 0xc);
    for (int j = validCount; j < 8; slot++, j++) {
        struct CombatantStruct* c = GetCombatantUnchecked(battle, j + 0xc0);
        *slot = c;
        if (c) {
            struct Vec3_021e75a4 tmp = *(struct Vec3_021e75a4*)((char*)c + 0x44);
            Vector3fix_Add((struct Vec3*)&accum, (struct Vec3*)&tmp, (struct Vec3*)&accum);
            validCount++;
        }
    }
    _Z22Vector3fixDivideScalarPK8Vector3iiPS_((struct Vec3_02030ef0*)&accum, validCount << 0xc, (struct Vec3_02030ef0*)&accum);

    slot = arr;
    for (i = 0; i < validCount; slot++, i++) {
        void* c = *slot;
        if (c) {
            struct Vec3_021e75a4* cv = (struct Vec3_021e75a4*)((char*)c + 0x44);
            struct Vec3_021e75a4 rel = *cv;
            rel.x = rel.x - accum.x;
            _ZN8Vector3iaSERKS_((int*)cv, (int*)&rel);
        }
    }

    accum.x = 0;
    struct Entry021e75a4 entry;
    for (i = 0; i < 8; i++) {
        short id = (short)(i + 0xc0);
        void* c = GetCombatantUnchecked(battle, id);
        if (!c) {
            continue;
        }
        ResetFields_021de110(&entry);
        entry.f0 = 0;
        entry.f4 = 0x12c;
        entry.id = id;
        entry.val = 0x12c;
        _ZN8Vector3iaSERKS_((int*)entry.rel, (int*)&accum);
        PushNodeFromFreeList_021eee48(obj, (struct Rec021eee48*)&entry);
        _ZN8Object3D24MaybeSetRegularAnimationEPKci(c, data_ov025_021ef834, 0);
    }
    return 1;
}
