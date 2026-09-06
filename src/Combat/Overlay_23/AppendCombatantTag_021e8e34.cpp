#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

int GetFieldAt0x150(unsigned char* obj);

int AppendXTag(char* dst, int x);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov023_021e8e34  (semantic: AppendCombatantTag_021e8e34)
extern "C" ARM void func_ov023_021e8e34(void* obj) {
    if (*(int*)((char*)obj + 0x5f4) == 0) return;
    char* dst = *(char**)((char*)obj + 0x5d8);
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* search = func_0202ae18();
    int fieldPtr = 0;
    if (!CheckField0NonZero((int*)search)) {
        struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, 0);
        if (combatant) fieldPtr = GetFieldAt0x150((unsigned char*)combatant);
    } else {
        int id = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
        struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, id);
        if (combatant) fieldPtr = GetFieldAt0x150((unsigned char*)combatant);
    }
    if (fieldPtr == 0) return;
    char* str = (char*)fieldPtr + 0x3c;
    int len = strlen(str);
    int total = len * 5 + 6;
    int pad = (total / 8 + 1) * 8 - len * 5;
    pad = pad / 2;
    AppendXTag(dst, pad);
    AppendString02042058(dst, str);
}
