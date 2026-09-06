#include <globaldefs.h>

void* GetActiveCombatWork(void);

// USA: func_ov025_021e88b8  (semantic: SetActiveCombatFlagFf9_021e88b8)
extern "C" ARM int func_ov025_021e88b8(void) {
    void* obj = GetActiveCombatWork();
    if (obj) {
        *((char*)obj + 0x6ff9) = 1;
    }
    return 1;
}
