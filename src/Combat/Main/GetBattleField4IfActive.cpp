#include <globaldefs.h>

int GetBattleStateCode(void);
extern void* data_021142e0[];

// USA: func_020d46a8
ARM int GetBattleField4IfActive(void) {
    if (GetBattleStateCode()) return 0;
    return *(int*)((char*)data_021142e0[1] + 4);
}
