#include <globaldefs.h>

struct StatStageStruct02087a9c {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 9;
    int stage : 3;
};

void ClearBattleFlags0x14And0x5802087b14(void* obj);

// USA: func_02087a9c
ARM int SetStatStageBit9(struct StatStageStruct02087a9c* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x5802087b14(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x71) = 6;
    *((unsigned char*)p + 0x94) = 0;
    p->flags |= 0x2000;
    return p->stage;
}
