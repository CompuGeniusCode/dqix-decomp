#include <globaldefs.h>

int GetBattleStateCode(void);

// USA: func_020d4aa8
ARM int GetSharedHalfwordOrBattleDefault(void) {
    if (GetBattleStateCode()) return 0x8000;
    return *(unsigned short*)0x027ffcfa;
}
