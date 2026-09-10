#include <globaldefs.h>
#include "std_library_functions.h"

// Copies the combatant id list out of the global state root -- the bytes at +0x571d, count in the
// byte at +0x5721 -- and returns that count. The region is only four bytes wide, 0x571d..0x5720, so
// the list caps at four entries. Callers hand each byte to GetCombatantWithFlag0x100 or
// GetCombatantWithFlag0x800, and ov002's func_02154f4c writes 4 one past the end as a terminator,
// so the entries are combatant ids. func_020114c0 is the matching writer. Whether the list is the
// party in its current order or a selection made elsewhere is not established.
extern "C" ARM unsigned char CopyOutCombatantIdList(char* obj, void* dst) {
    unsigned char len = *(unsigned char*)(obj + 0x5721);
    memcpy(dst, obj + 0x571d, len);
    return *(unsigned char*)(obj + 0x5721);
}
