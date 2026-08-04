#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
int GetField5cb0Value(char* obj);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct BattleExt021e6594 {
    unsigned int : 29;
    unsigned int flag29 : 1;
    unsigned int : 2;
    signed int : 9;
    signed int field9 : 10;
    signed int : 13;
};

struct Sub0x150_021e6594 {
    char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char : 7;
    char pad1[0x950 - 0x49d];
    int f950;
};

// USA: func_ov023_021e6594  (semantic: BuildEntryBuffers_021e6594)
extern "C" ARM void func_ov023_021e6594(char* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct BattleExt021e6594* ext = (struct BattleExt021e6594*)((char*)battleStruct + 0x569c);
    if (!ext->flag29) {
        void* entry;
        if (GetField5cb0Value((char*)battleStruct) == 1) {
            entry = FindEntryByKey((struct TableA68*)(obj + 0x133c), 0x50e9);
        } else {
            func_0202ae18();
            struct CombatantStruct* combatant = GetCombatantAtField0x3ac(battleStruct);
            struct Sub0x150_021e6594* sub = *(struct Sub0x150_021e6594**)((char*)combatant + 0x150);
            int key = 0x50dc;
            if (sub->bit0 == 1) key += 0x32;
            key += sub->f950;
            entry = FindEntryByKey((struct TableA68*)(obj + 0x133c), (short)key);
        }
        memset(obj + 0x1400, 0, 0x40);
        int len = strlen((char*)entry);
        memcpy(obj + 0x1400, (char*)entry, len);
    }
    if (ext->field9 != 0x12c) return;
    memset(obj + 0x1440, 0, 0x40);
    void* entry2 = FindEntryByKey((struct TableA68*)(obj + 0x133c), 0x283c);
    int len2 = strlen((char*)entry2);
    memcpy(obj + 0x1440, (char*)entry2, len2);
}
