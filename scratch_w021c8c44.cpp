#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);
extern "C" void func_0202738c(void* a, int b, int c, int d);
extern "C" void func_02027304(void* a, int b);
extern "C" void* func_ov017_021b86f8(void* a, int b, int c, int d);
extern "C" int func_0202c508(void* obj);
void* GetData02108ea8(void);
struct Entry0207d9bc;
void ResetEntryByKey0207da7c(struct Entry0207d9bc* arr, unsigned short key);
void EnqueueEventForFlaggedCombatants_021a33e0(void* unused, int key);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(struct Obj02053f7c* obj, short a, int b);
void CallHelperWithBuf_021907dc(int a, int b, int c, int d, int e);
void ClearMatchingHalfword_02197324(unsigned char* obj, unsigned short key);
struct SearchStruct0202c1a4;

struct Arr4Words_021c8c44 { int w[4]; };
extern struct Arr4Words_021c8c44 data_ov017_021d6d18;

struct Evt021c8c44 {
    unsigned char pad0[4];
    int field4;
    unsigned short field8;
    unsigned char fieldA;
};

// USA: func_ov017_021c8c44
ARM void ApplyEventTag_021c8c44(int p0, struct Evt021c8c44* evt, struct BattleStruct* battleStruct2, unsigned char* table, struct SearchStruct0202c1a4* search) {
    unsigned short field8 = evt->field8;
    int field4 = evt->field4;
    int flagA = evt->fieldA != 0;

    struct BattleStruct* battleStruct = GetBattleStruct();
    int t = func_ov017_0218b5b0() + 0x3000;
    void* mgrField6d0 = *(void**)(t + 0x6d0);

    int i;
    for (i = 0; i < 4; i++) {
        int match = (i == p0);
        if (!match) {
            struct CombatantStruct* c = GetCombatantWithFlag0x1000(battleStruct, i);
            if (c != NULL) {
                match = (p0 == GetSignedByte0x2d0(c));
            }
        }
        if (match) {
            func_0202738c(mgrField6d0, 0, 1, i);
            func_02027304(mgrField6d0, i);
        }
    }

    void* tableField718 = *(void**)(table + 0x3000 + 0x718);
    func_ov017_021b86f8(tableField718, field8, 1, flagA);

    if (func_0202c508(search) != 0) {
        void* d = GetData02108ea8();
        ResetEntryByKey0207da7c((struct Entry0207d9bc*)d, (unsigned short)field8);
        if (field4 != -1) {
            struct Arr4Words_021c8c44 arr = data_ov017_021d6d18;
            int matchCount = 0;
            int idx;
            for (idx = 0; idx < 4; idx++) {
                struct CombatantStruct* c2 = GetCombatantWithFlag0x800(battleStruct2, idx);
                if (c2 != NULL) {
                    if (field4 == GetU16At0x6((struct U16Field0x6_020375f8*)c2) || field4 == *(int*)((char*)c2 + 0x15c)) {
                        arr.w[matchCount] = idx;
                        matchCount++;
                    }
                }
            }
            if (matchCount == 1 && arr.w[0] != 0) {
                EnqueueEventForFlaggedCombatants_021a33e0(table, field4);
            }
        }
    }

    int j;
    for (j = 0; j < 4; j++) {
        struct CombatantStruct* c3 = GetCombatantWithFlag0x100(battleStruct2, j);
        if (c3 != NULL) {
            if (p0 == *(short*)((char*)c3 + 0x4)) {
                SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c3, 0, 1);
            } else if (c3->flags & 0x1000) {
                struct CombatantStruct* c4 = GetCombatantWithFlag0x100(battleStruct2, 0);
                if (c4 != NULL) {
                    unsigned short v = *(unsigned short*)((char*)c4 + 0x100 + 0xb2);
                    SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c3, v, 1);
                }
            }
        }
    }

    CallHelperWithBuf_021907dc((int)table, p0, 1, 1, 1);
    ClearMatchingHalfword_02197324(table, field8);
}
