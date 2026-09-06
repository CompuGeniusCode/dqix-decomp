#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_02040c2c(void* entry, int a, int b, unsigned int c);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
int GetField0x3b4Value(struct BattleStruct* battleStruct);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Entry0203dd20 {
    unsigned int flags;
};

struct Obj0203dd20 {
    char pad0[0xc];
    struct Entry0203dd20* entries[0x20];
};

// USA: func_0203dd20
ARM void ApplyScaleToCombatants0203dd20(struct Obj0203dd20* obj) {
    struct BattleStruct* battleStruct;
    int a;
    int b;
    unsigned int c;
    int i;
    battleStruct = GetBattleStruct();
    a = GetField0x3b0Value(battleStruct);
    b = GetField0x3b4Value(battleStruct);
    c = GetBattleScaleCount(battleStruct);
    for (i = 0; i < 0x20; i++) {
        struct Entry0203dd20* entry = obj->entries[i];
        if (entry != NULL && !(entry->flags & 0x8000)) {
            func_02040c2c(entry, a, b, c);
        }
    }
}
