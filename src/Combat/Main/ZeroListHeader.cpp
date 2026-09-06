#include <globaldefs.h>

struct Struct02072488 {
    void* field0;
    unsigned short field4;
    unsigned short field6;
};

// USA: func_02072488
ARM void ZeroListHeader(struct Struct02072488* s) {
    s->field0 = NULL;
    s->field4 = 0;
    s->field6 = 0;
}
