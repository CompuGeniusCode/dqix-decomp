#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct List02160094;
struct ListNode02160094;
struct BitFlags02037170;
struct S190;

struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
int GetByte0x40Bit0(struct BitFlags02037170* obj);
int GetByte0x40Bit1(struct S190* obj);
extern int data_ov025_021ef988;

// USA: func_ov025_021e2c34
ARM int CheckFlagsOrBits_021e2c34(void* unused, struct List02160094* list) {
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, 0);
    if (!node) return 0;
    int id = *(unsigned short*)((char*)node + 0x20);
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantUnchecked(battle, id);
    int flags = *(int*)((char*)&data_ov025_021ef988 + 0x1c);
    if (flags & 4) return 0;
    if (GetByte0x40Bit0((struct BitFlags02037170*)c)) return 1;
    return GetByte0x40Bit1((struct S190*)c) != 0;
}
