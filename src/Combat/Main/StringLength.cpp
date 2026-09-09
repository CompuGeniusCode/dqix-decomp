#include <globaldefs.h>

// Plain strlen. The MSL strlen already sits at 0x02003f0c, so this is a second copy; both are
// used widely, neither is dead. This one has 107 call edges across 16 modules -- the tag
// appenders at 0x02041a28..0x0204201c and StringReplaceLanguageTag, but also ov002
// LoadItemNameTable, ov000 ProcessCombatTurn, ov031, ov020 and ov019 -- so it is the game's
// general strlen rather than the message builders' private one.
extern "C" ARM int StringLength(const char* s) {
    int i = 0;
    if (s[i] != 0) {
        do {
            i++;
        } while (s[i] != 0);
    }
    return i;
}
