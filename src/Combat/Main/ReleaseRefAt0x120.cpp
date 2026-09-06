#include <globaldefs.h>

struct BattleTarget9a8;
void ClearTargetMask(struct BattleTarget9a8*);

// USA: func_020bf2d4
ARM void ReleaseRefAt0x120(void *obj) {
    if (*(int *)((char *)obj + 0x120) == 0) return;
    if ((*(int *)((char *)obj + 0x120) -= 1) != 0) return;
    ClearTargetMask((struct BattleTarget9a8*)obj);
}
