#include <globaldefs.h>

struct StatStageStruct020877c0 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage : 3;
};

void ClearBattleFlags0x14And0x5802087838(void* obj);

// USA: func_020877c0  (semantic: SetStatStageBit0)
extern "C" ARM int func_020877c0(struct StatStageStruct020877c0* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x5802087838(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x6e) = 5;
    *((unsigned char*)p + 0x91) = 0;
    p->flags |= 0x400;
    return p->stage;
}
