#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b4Value(struct BattleStruct* battleStruct);

extern "C" void func_0207051c(void* p, unsigned short field2, int val);

struct Timer020707c8 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    float fieldC;
    int field10;
};

// USA: func_020707c8
ARM void UpdateInterpTimer020707c8(struct Timer020707c8* p) {
    int delta = GetField0x3b4Value(GetBattleStruct());
    int field8 = p->field8;
    if (field8 > 0) {
        p->fieldC += (float)delta * (((float)p->field4 - p->fieldC) / (float)field8);
    }
    p->field8 -= delta;
    if (p->field8 <= 0) {
        p->fieldC = (float)p->field4;
        p->field8 = 0;
        if (p->field4 == 1) p->field0 = 0;
    }
    func_0207051c(p, p->field2, (int)p->fieldC);
    if (p->field8 > 0) return;
    if (p->field10 <= 0) return;
    p->field8 = (int)((float)p->field10 * 16.66699981689453f);
    p->field4 = 1;
    p->field10 = 0;
}
