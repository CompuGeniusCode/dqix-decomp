#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

void ClearBitsInField0x6c(unsigned char* obj, unsigned int mask);

struct S02037418;
void SetFieldAAndSync02037418(struct S02037418* obj, int val);

extern "C" void* func_ov017_0218b5b0(void);
extern "C" struct Vec3 func_02034104(void* combatant);
extern "C" void func_020c2f18(void* a, void* b);
extern "C" int func_020c338c(int x, int z);

extern char data_02108760;

struct Entity02078898 {
    char pad0[0x6];
    unsigned short field6;              // 0x6
    char pad1[0x44 - 0x8];
    struct Vec3 vecField44;             // 0x44
    char pad2[0xb2 - 0x50];
    unsigned short fieldB2;             // 0xb2
    char pad3[0x166 - 0xb4];
    unsigned short combatantIdField;    // 0x166
    char pad4[0x17c - 0x168];
    unsigned char field17c;             // 0x17c
};

// USA: func_02078898
ARM int SyncCombatantPosition02078898(struct Entity02078898* p) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned short id = p->combatantIdField;
    struct CombatantStruct* combatant = GetCombatantWithFlag0x2(bs, id);
    if (combatant == 0) return 0;

    void* ov = func_ov017_0218b5b0();
    char* g = (char*)ov + 0x3000;
    void* g734 = *(void**)(g + 0x734);

    struct CombatantStruct* other = GetCombatantAtField0x3ac(bs);
    unsigned short a = GetU16At0x6((struct U16Field0x6_020375f8*)other);
    unsigned short b = GetU16At0x6((struct U16Field0x6_020375f8*)p);
    if (a == b && *((unsigned char*)g734 + 3) == 0) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 6, 0);
    }

    struct Vec3 pos = func_02034104(combatant);
    struct Vec3 diff;
    SubtractVec3(&pos, &p->vecField44, &diff);
    func_020c2f18(&diff, &diff);
    int angle = func_020c338c(diff.x, diff.z);
    SetVecYByMode02033834((struct Obj02033834*)p, angle);

    p->fieldB2 = 0;
    SetByteIfChanged02033b68((struct Obj02033b68*)p, 0);
    ClearBitsInField0x6c((unsigned char*)p, 0x80);
    SetFieldAAndSync02037418((struct S02037418*)p, 0x1f);
    p->field17c = 0;
    return 1;
}
