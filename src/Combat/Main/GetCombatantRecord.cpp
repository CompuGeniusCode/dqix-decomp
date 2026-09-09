#include <globaldefs.h>

// Returns the record a combatant is bound to. func_02053c4c installs the pointer at
// +0x150 and derives the base stats (+0x134) and modifiable stats (+0x138) from the record's +0x3c
// and +0x94, so the name at +0x3c and the start of the base stats are one address. The rest lives
// here too: per-vocation levels at +0x16c, revocation counts at +0x186 (thirteen each), held-item
// ids at +0x454, the id func_02053c74 stamps at +0x568, the palette index at
// +0x56a. Records come from a pool in the game state root and presumably outlive the slot.
extern "C" ARM int GetCombatantRecord(unsigned char* obj) {
    return *(int*)(obj + 0x150);
}
