#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct ScrollState020a63f8 {
    int x;
    int y;
    signed char dx;
    signed char dy;
    signed char unk_a;
    unsigned char frozen;
};

// USA: func_020a63f8
ARM void AnimateSubBG1Scroll020a63f8(struct ScrollState020a63f8* p) {
    GetBattleStruct();
    if (p->frozen) {
        return;
    }
    *(volatile unsigned int*)0x4001014 = (p->x & 0x1ff) | ((p->y << 16) & 0x1ff0000);

    p->x += p->dx;
    if (p->x >= 0x100) {
        p->x -= 0x100;
    }
    if (p->x <= -1) {
        p->x += 0x100;
    }

    p->y += p->dy;
    if (p->y >= 0x100) {
        p->y -= 0x100;
    }
    if (p->y <= -1) {
        p->y += 0x100;
    }
}
