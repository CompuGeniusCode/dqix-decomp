#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "System/Memory.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* obj);
int GetField0x3acValue(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);

struct Obj021f9bb0 {
    char pad[0x28];
    unsigned short field28;
};
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);

struct NameBuf02046574 { char c[0x40]; };
struct Obj02046574 {
    char pad[0x4ac];
    struct NameBuf02046574 names[16];
};
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void CopyStringToIndexedField0x2ec(char* base, int index, char* src);

extern unsigned char* data_ov004_02171010;

// USA: func_ov004_02164e40  (semantic: BuildTableNameForNode_02164e40)
extern "C" ARM int func_ov004_02164e40(void* obj) {
    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);

    struct BattleStruct* battle = GetBattleStruct();
    GetField0x3acValue(battle);
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);

    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;

    unsigned int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)node);

    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);

    unsigned char* base = data_ov004_02171010;
    unsigned int off = idx * 0x1c4;
    unsigned char* krow = base + 0xad5;
    krow = krow + off;
    unsigned char kind = *krow;
    if (kind == 1) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0x63);
    } else if (kind == 2) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0xf8);
    }

    if (combatant) {
        char* name = (char*)combatant->baseStats;
        SetIndexedName02046574((struct Obj02046574*)g, 0, name);
    }
    CopyStringToIndexedField0x2ec((char*)g, 0, buf);
    return 0;
}
