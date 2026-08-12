#include <globaldefs.h>

void* GetActiveCombatWork(void);

// USA: func_ov025_021e8898  (semantic: SetActiveCombatFlagFd8_021e8898)
extern "C" ARM int func_ov025_021e8898(void) {
    void* obj = GetActiveCombatWork();
    if (obj) {
        *((char*)obj + 0x6fd8) = 1;
    }
    return 1;
}
