#include <globaldefs.h>

struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// USA: func_020de234
ARM unsigned short GetPreferredPackedField020de234(StructDE234_020de234* p, int preferMid) {
    if (p->g <= 0) {
        return 999;
    }
    if (!preferMid) {
        if (p->field10Low != 999) {
            return p->field10Low;
        }
        return p->field10Mid;
    } else {
        if (p->field10Mid != 999) {
            return p->field10Mid;
        }
        return p->field10Low;
    }
}
