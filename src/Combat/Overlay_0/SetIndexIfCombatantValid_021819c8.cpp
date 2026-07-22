#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct ListNode02160094 {
    char pad[0x30];
    struct ListNode02160094* next;
};

struct List02160094 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct ListNode02160094* head;
};
extern struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);

extern struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_021819c8  (semantic: SetIndexIfCombatantValid_021819c8)
extern "C" ARM int func_ov000_021819c8(struct List02160094* list, int index, int* out, int flag) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, index);
    if (node != NULL) {
        int computed = 0;
        if (flag == 0) {
            computed = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1c;
        } else if (flag == 1) {
            computed = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1d;
        }

        struct CombatantStruct* combatant = GetCombatantUnchecked(battleStruct, computed);
        if (combatant != NULL) {
            if (*(short*)((char*)combatant + 0x2) > -1) {
                *out = computed;
                return 1;
            }
        }
    }
    return 0;
}
