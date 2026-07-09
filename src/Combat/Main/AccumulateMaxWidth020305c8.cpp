#include <globaldefs.h>

struct CombatantWidth020305c8 {
    char unk[0x40];
    unsigned short f40;
    unsigned short f42;
};

struct BattleWidth020305c8 {
    char unk[0x118];
    unsigned int f118;
    unsigned int f11c;
    unsigned int f120;
    unsigned int f124;
    struct CombatantWidth020305c8 list[1];
};

// USA: func_020305c8
ARM void AccumulateMaxWidth020305c8(struct BattleWidth020305c8* b) {
    struct CombatantWidth020305c8* c;
    unsigned int i;
    unsigned int v;
    unsigned int cur;
    unsigned int sum;
    b->f118 = 0;
    for (c = b->list, i = 0; i < b->f124; i++, c++) {
        if (c->f42 != 0) {
            v = (c->f40 + c->f42) << 2;
            cur = b->f118;
            if (cur <= v) {
                cur = v;
            }
            b->f118 = cur;
        }
    }
    sum = b->f118 + b->f11c;
    if (sum > b->f120) {
        b->f120 = sum;
    }
}
