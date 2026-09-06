#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);

struct ListNode02057f00 {
    int value;
    char pad[0x1ec - 4];
    struct ListNode02057f00* next;
};

struct Obj02057f00 {
    struct ListNode02057f00* head;
};

// USA: func_02057f00  (semantic: ClearCombatantSlotsAndUnlinkNode_02057f00)
extern "C" ARM void func_02057f00(void* obj, int value) {
    struct ListNode02057f00* node = ((struct Obj02057f00*)obj)->head;
    struct ListNode02057f00* prev = 0;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int i;
    for (i = 0; i < 16; i++) {
        if (value == *(int*)((char*)obj + i * 0xd4 + 0xd8)) {
            ClearCombatantSlot(battleStruct, i + 0xd0);
        }
    }
    while (node != 0) {
        if (value == node->value) break;
        prev = node;
        node = node->next;
    }
    if (node == 0) return;
    if (prev == 0) {
        ((struct Obj02057f00*)obj)->head = node->next;
    } else {
        prev->next = node->next;
    }
}
