#include <globaldefs.h>

struct StatStageStruct02087b90 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 12;
    int stage : 3;
};

void ClearBattleFlags0x14And0x5802087c08(void* obj);

// USA: func_02087b90
ARM int SetStatStageBit12(struct StatStageStruct02087b90* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x5802087c08(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x72) = 5;
    *((unsigned char*)p + 0x95) = 0;
    p->flags |= 0x4000;
    return p->stage;
}
