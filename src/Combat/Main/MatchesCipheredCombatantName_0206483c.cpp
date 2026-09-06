#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);

// USA: func_0206483c  (semantic: MatchesCipheredCombatantName_0206483c)
extern "C" ARM int func_0206483c(void* unused0, char* name) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, 0);
    char* subject = (char*)GetFieldAt0x150((unsigned char*)combatant) + 0x3c;
    int len = strlen(subject);
    int i;
    int evenMatch;

    for (i = 0; i < len; name++, subject++, i++) {
        if ((i % 2) == 0) {
            if (*name == *subject) {
                evenMatch = 1;
            } else {
                evenMatch = 0;
            }
        } else if (evenMatch) {
            if (*name != *subject) {
                return 0;
            }
        } else {
            unsigned char c1 = *(unsigned char*)name;
            unsigned char c2 = *(unsigned char*)subject;
            int shift = 0x5f;
            if (c1 > 0x7f) {
                shift = 0x5e;
            }
            int shifted = (c1 + shift) & 0xff;
            if (shifted != c2) {
                return 0;
            }
        }
    }
    return 1;
}
