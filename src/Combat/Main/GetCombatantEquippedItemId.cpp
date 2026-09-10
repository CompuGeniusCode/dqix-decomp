#include <globaldefs.h>

struct Field150Table02052df8 {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052df8 {
    char pad[0x150];
    struct Field150Table02052df8* table;
};

// Returns the item id equipped in one of the combatant's slots, or -1 when the character block at
// 0x150 is absent. func_ov003_02179cfc hands the result straight to FindItemRecordById, taking the
// index from a nine-entry table keyed by a four-bit slot selector -- [7, 8, 0, 1, 6, 4, 5, 9, -1],
// eight real slots and a sentinel, so the array at +0x488 is the equipment list, and that last
// entry makes the caller's -1 path reachable through the table as well. The writer at 0x02052d7c
// raises a global change bit for every index except 7 and 8, and sets a separate byte for 9.
extern "C" ARM int GetCombatantEquippedItemId(struct Field150Holder02052df8* obj, int index) {
    struct Field150Table02052df8* table = obj->table;
    return table ? table->entries[index] : -1;
}
