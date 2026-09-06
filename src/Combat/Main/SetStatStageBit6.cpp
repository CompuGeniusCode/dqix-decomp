#include <globaldefs.h>

struct StatStageStruct020879a8 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 6;
    int stage : 3;
};

void ClearBattleFlags0x14And0x5802087a20(void* obj);

// USA: func_020879a8  (semantic: SetStatStageBit6)
extern "C" ARM int func_020879a8(struct StatStageStruct020879a8* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x5802087a20(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x70) = 6;
    *((unsigned char*)p + 0x93) = 0;
    p->flags |= 0x1000;
    return p->stage;
}
