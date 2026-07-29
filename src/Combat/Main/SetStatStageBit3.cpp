#include <globaldefs.h>

struct StatStageStruct020878b4 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 3;
    int stage : 3;
};

void ClearBattleFlags0x14And0x580208792c(void* obj);

// USA: func_020878b4  (semantic: SetStatStageBit3)
extern "C" ARM int func_020878b4(struct StatStageStruct020878b4* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x580208792c(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x6f) = 6;
    *((unsigned char*)p + 0x92) = 0;
    p->flags |= 0x800;
    return p->stage;
}
