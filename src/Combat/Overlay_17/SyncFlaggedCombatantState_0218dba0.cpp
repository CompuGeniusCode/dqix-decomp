#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_02012fe4(void);

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);

void* GetFieldPtrAt0x26c(void* obj);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

int GetFieldMasked0x6c(void* obj, int mask);
int GetIntAt0x64(unsigned char* obj);

struct Vec3_37774;
struct Src_37774;
void BuildVec3FromScatteredFields(struct Vec3_37774* dst, struct Src_37774* src);

struct S02037484;
int MulFieldsDiv3102037484(struct S02037484* obj);

void SyncBattleState0208f87c(void* self, int b, int c, int d);
void InvokeHandlerAndClearFlags020b3814(void);

struct Vec3Local_0218dba0 { unsigned int v[3]; };

// USA: func_ov017_0218dba0  (semantic: SyncFlaggedCombatantState_0218dba0)
extern "C" ARM void func_ov017_0218dba0(int combatantId) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battle, combatantId);
    if (combatant == 0) {
        return;
    }
    if (CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)combatant) != 0) {
        return;
    }

    unsigned short tag;
    int f8c;
    void* headArr;

    void* ovBase = func_ov017_0218b5b0();
    headArr = *(void**)((char*)ovBase + 0x36fc);
    void* misc = func_02012fe4();
    tag = *(unsigned short*)((char*)misc + 0x38);
    f8c = *(int*)((char*)misc + 0x3c);

    struct Vec3Local_0218dba0 selfVec;
    struct Vec3Local_0218dba0 tmp;
    BuildVec3FromScatteredFields((struct Vec3_37774*)&tmp, (struct Src_37774*)combatant);
    selfVec = tmp;

    int mulResult = MulFieldsDiv3102037484((struct S02037484*)combatant);
    float t = (float)f8c / 31.0f;
    int d = (int)(t * (float)mulResult);

    if (combatant != 0) {
        unsigned char* base = (unsigned char*)GetFieldPtrAt0x26c(combatant);
        if (base[0] != 0) {
            base = (unsigned char*)GetFieldPtrAt0x26c(combatant);
            unsigned char mode = base[1];
            if (mode == 1 || mode == 4) {
                d = *(short*)(base + 0x50);
            }
            if (mode == 2 || mode == 6) {
                d = *(short*)(base + 0x50);
                selfVec.v[1] = *(unsigned int*)(base + 0x4c);
            }
        }
    }

    if (*(short*)((char*)GetField0x3f8Address(battle) + 0x6c) == 0x270f) {
        if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)headArr) == 3) {
            d = 0;
        }
    }

    if (GetFieldMasked0x6c(combatant, 0x10) == 0) {
        int c = (int)(0.9f * (float)GetIntAt0x64((unsigned char*)combatant));
        volatile int pad8 = 8;
        SyncBattleState0208f87c(&selfVec, tag, c, d);
    } else {
        InvokeHandlerAndClearFlags020b3814();
    }
}
