#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b4Value(struct BattleStruct* battleStruct);

struct DualInterp_0203af48 {
    char pad0[0xc];
    float curX;         // 0x0c
    int targetX;         // 0x10
    int remainingX;      // 0x14
    float curY;          // 0x18
    int targetY;         // 0x1c
    int remainingY;      // 0x20
    char pad24[2];        // 0x24
    unsigned char flagX; // 0x26
    unsigned char flagY; // 0x27
};

// USA: func_0203af48
extern "C" ARM int func_0203af48(struct DualInterp_0203af48* p) {
    int delta = GetField0x3b4Value(GetBattleStruct());
    int remainingX = p->remainingX;
    int hasX = remainingX > 0;
    if (hasX) {
        p->curX += (float)delta * (((float)p->targetX - p->curX) / (float)remainingX);
        int newRemainingX = p->remainingX - delta;
        p->remainingX = newRemainingX;
        if (newRemainingX <= 0) {
            p->curX = (float)p->targetX;
        }
        p->flagX = 1;
    }
    int remainingY = p->remainingY;
    int hasY = remainingY > 0;
    if (!hasY) {
        return hasY;
    }
    p->curY += (float)delta * (((float)p->targetY - p->curY) / (float)remainingY);
    int newRemainingY = p->remainingY - delta;
    p->remainingY = newRemainingY;
    if (newRemainingY <= 0) {
        p->curY = (float)p->targetY;
    }
    p->flagY = 1;
    return 1;
}
