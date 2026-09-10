#include <globaldefs.h>

struct CharacterRecord {
    char unknown0[0x488];
    short equippedItemIds[10];
};
struct Combatant {
    char unknown0[0x150];
    struct CharacterRecord* record;
};

// Returns a character's equipped item ids: ten halfwords at +0x488 of the record hung off the
// combatant at +0x150. ov004's func_ov004_02159650 maps an item's 4-bit slot type through a table
// into the same array - via the indexed getter GetCombatantEquippedItemId, not this one - and names what is worn
// there with FindItemRecordById; func_020dd718 scans all ten for a given item. The
// setter func_02052d7c dirties a global appearance bit for every index but 7 and 8, which seem to be
// the non-visible slots. func_02052e14 is a byte-identical accessor.
extern "C" ARM short* GetEquippedItemIds(struct Combatant* combatant) {
    struct CharacterRecord* record = combatant->record;
    return record ? &record->equippedItemIds[0] : NULL;
}
