#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Memory.h"
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void*);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void* GetField0x649eForValidIndex(char* base, unsigned int index);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void CopyStringToIndexedField0x2ec(char* base, int index, char* src);

// USA: func_ov004_02165d74
ARM int SetIndexedNameFromField_02165d74_02165d74(void* a) {
    int g = GetGlobalField0x1c020421a0();
    func_02046380((void*)g);
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(bs);
    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);
    strcpy(buf, (char*)GetField0x649eForValidIndex((char*)bs, 0));
    if (combatant != NULL) {
        SetIndexedName02046574((struct Obj02046574*)g, 0, *(char**)((char*)combatant + 0x134));
    }
    CopyStringToIndexedField0x2ec((char*)g, 0, buf);
    return 0;
}
