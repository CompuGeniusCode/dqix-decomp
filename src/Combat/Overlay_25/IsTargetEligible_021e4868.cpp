#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct S0204a438;
void* GetField0x21c(struct S0204a438* p);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
int GetFlags(int obj);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct BitFlags02037170;
int GetByte0x40Bit0(struct BitFlags02037170* obj);
struct BitFlags02037180;
int GetByte0x40Bit2(struct BitFlags02037180* obj);
int GetFieldMasked0x6c(void* obj, int mask);
extern int data_ov025_021ef988;

struct NameArr021e4868 { const char* v[8]; };
extern struct NameArr021e4868 data_ov025_021eef58;

struct Param021e4868 { char pad[8]; unsigned char field8; char pad1; short fieldA; };

struct Local021e4868 {
    struct NameArr021e4868 names;
    int id;
    char pad[0x1c];
};

// USA: func_ov025_021e4868  (semantic: IsTargetEligible_021e4868)
extern "C" ARM int func_ov025_021e4868(struct Param021e4868* p, int b, int unused2, int d) {
    struct Local021e4868 local;
    void* obj;
    unsigned int i;

    if (*(int*)((char*)&data_ov025_021ef988 + 0x1c) & 4) {
        return 0;
    }
    struct BattleStruct* battle = GetBattleStruct();
    if (p->field8 == 0x19) {
        int val = GetField0x3b0Value(battle);
        if (GetFlags(val) & 0x10) {
            obj = GetField0x21c((struct S0204a438*)val);
        } else {
            return 1;
        }
    } else {
        if (DispatchByIndex021820bc((void*)d, b, p->field8, (int)&local.id) != 1) {
            return 1;
        }
        obj = GetCombatantUnchecked(battle, local.id);
    }
    if (!obj) {
        return 1;
    }
    if (p->fieldA < 0x1000) {
        return *(int*)((char*)obj + 0x24) >= p->fieldA;
    }
    if (GetByte0x40Bit0((struct BitFlags02037170*)obj) || GetByte0x40Bit2((struct BitFlags02037180*)obj)) {
        return 1;
    }
    if (GetFieldMasked0x6c(obj, 0x40000)) {
        return 1;
    }
    if (*(unsigned char*)((char*)obj + 0x19) & 1) {
        goto ReturnZero;
    }
    char* name = *(char**)((char*)obj + 0x14);
    if (!name) {
        goto ReturnZero;
    }
    local.names = data_ov025_021eef58;
    {
        const char** entry = local.names.v;
        for (i = 0; i < 8; i++, entry++) {
            if (strcmp(name, *entry) == 0) {
                return 1;
            }
        }
    }
ReturnZero:
    return 0;
}
