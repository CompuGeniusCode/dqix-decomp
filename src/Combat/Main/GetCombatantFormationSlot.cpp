#include <globaldefs.h>

// Returns the combatant's battle formation slot, the byte at 0x1c of the substruct hanging off the
// combatant at 0x13c, or 0xff when that substruct is absent. Battle setup takes a default slot from
// a table indexed by how many combatants are in the group, replaces it with this value when it is
// not 0xff, then turns the slot into a position on a nine-wide staggered grid; an ov017 event tag
// writes the same byte for the four party members and the eight enemies, 0xff meaning leave alone.
// The setter at 0x02049390 refuses to store 0xff, so the sentinel can only be cleared, never set.
extern "C" ARM int GetCombatantFormationSlot(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x1c] : 0xff;
}
