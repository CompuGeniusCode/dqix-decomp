#include <globaldefs.h>

// Tests one bit of the four-bit mask at +0x34, indexed by party slot. func_ov017_021b848c is the
// builder: it sets slot i only when a caller-supplied per-slot byte is nonzero and
// GetCombatantUnchecked(i) is non-null, so a set bit means that slot is occupied and taking part.
// Consumers match -- func_ov000_02163b90 shows or hides those members' Object3D,
// func_ov017_021c6bc8 broadcasts one stat message each, and func_ov000_02167f10 walks 0..3 and
// then enemy ids 0xc0..0xc7 separately, so 0..3 really is the player's party.
extern "C" ARM int IsPartyMemberPresent(unsigned char* obj, unsigned int index) {
    if (index >= 4) {
        return 0;
    }
    return obj[0x34] & (1 << index);
}
