#include <globaldefs.h>

struct Field150Table02052e2c {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052e2c {
    char pad[0x150];
    struct Field150Table02052e2c* table;
};

// Returns a character's equipped item ids: ten halfwords at +0x488 of the record hung off the
// combatant at +0x150. ov004's func_ov004_02159650 maps an item's 4-bit slot type through a table
// into the same array - via the indexed getter GetCombatantEquippedItemId, not this one - and names what is worn
// there with FindItemRecordById; func_020dd718 scans all ten for a given item. The
// setter func_02052d7c dirties a global appearance bit for every index but 7 and 8, which seem to be
// the non-visible slots. func_02052e14 is a byte-identical accessor.
extern "C" ARM short* GetEquippedItemIds(struct Field150Holder02052e2c* obj) {
    struct Field150Table02052e2c* table = obj->table;
    return table ? &table->entries[0] : NULL;
}
