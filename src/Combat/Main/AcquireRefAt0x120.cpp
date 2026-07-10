#include <globaldefs.h>

struct BattleTarget948;
int BuildTargetMaskFromBytes(struct BattleTarget948*, int, unsigned char*);

// USA: func_020bf29c
ARM int AcquireRefAt0x120(void *obj, int a, int b) {
    if (*(int *)((char *)obj + 0x120) == 0) {
        if (BuildTargetMaskFromBytes((struct BattleTarget948*)obj, a, (unsigned char*)b) == 0) return 0;
    }
    *(int *)((char *)obj + 0x120) += 1;
    return 1;
}
