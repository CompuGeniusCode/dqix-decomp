#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(void);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct ListNode0x2037a50;
int IsListNodeAttached0x2037a50(struct ListNode0x2037a50* node);
int GetFieldMasked0x6c(void* obj, int mask);
void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);
extern "C" int func_02035a2c(void* obj, int flag);
struct Bits40_37464;
int GetField0x40Bits3To7(struct Bits40_37464* obj);
int GetIntAt0x64(unsigned char* obj);

struct Vec3_37774 { int a[3]; };
struct Src_37774;
void BuildVec3FromScatteredFields(struct Vec3_37774* dst, struct Src_37774* src);
void SyncBattleState0208f87c(void* self, int b, int c, int d);

struct SyncLocal_021973e8 {
    int tag;
    struct Vec3_37774 vec;
};

// USA: func_ov017_021973e8  (semantic: SyncCombatantsInRange_021973e8)
extern "C" ARM void func_ov017_021973e8(unsigned int* flagsObj) {
    struct BattleStruct* bs = GetBattleStruct();
    void* ctx = func_02012fe4();
    unsigned short field38 = *(unsigned short*)((char*)ctx + 0x38);
    unsigned int field3c = *(unsigned int*)((char*)ctx + 0x3c);

    if (GetBitsInField4(flagsObj, 0x100) != 0) return;

    int flag9 = 1;
    if (GetBitsInField4(flagsObj, 0x1000) != 0) {
        flag9 = 0;
    }

    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        struct CombatantStruct* c = GetCombatantUnchecked(bs, id);
        if (!c) continue;
        if (IsListNodeAttached0x2037a50((struct ListNode0x2037a50*)c)) continue;
        if (GetFieldMasked0x6c(c, 0x40000000) != 0) continue;
        SetBitsInField0x6c((unsigned char*)c, 4);
        if (!func_02035a2c(c, flag9)) continue;
        if (GetFieldMasked0x6c(c, 0x10) != 0) continue;

        int bits = GetField0x40Bits3To7((struct Bits40_37464*)c);
        int computed = (int)((float)field3c / 31.0f * (float)bits);

        struct SyncLocal_021973e8 local;
        BuildVec3FromScatteredFields(&local.vec, (struct Src_37774*)c);
        int intAt64 = GetIntAt0x64((unsigned char*)c);
        local.tag = 8;
        SyncBattleState0208f87c(&local.vec, field38, intAt64, computed);
    }
}
