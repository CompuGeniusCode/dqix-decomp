#include <globaldefs.h>
#include "std_library_functions.h"

// The twin of CopyOutCombatantIdList one field lower: four bytes at +0x5718, count at +0x571c, and
// consumers pass each byte to GetCombatantWithFlag0x100, which indexes the combatant array and tests flags &
// 0x100, so they are combatant ids. The one writer, func_ov017_02191234, puts only this console's
// own combatants here -- the id GetLocalPlayerCombatantId returns plus the members owned by that
// slot -- while the +0x571d list gets every combatant; in single player the two come out identical.
// ov023 skips index 0 when counting party members, so entry 0 is presumably the hero.
extern "C" ARM unsigned char CopyOutLocalPlayerCombatantIds(char* obj, void* dst) {
    unsigned char len = *(unsigned char*)(obj + 0x571c);
    memcpy(dst, obj + 0x5718, len);
    return *(unsigned char*)(obj + 0x571c);
}
