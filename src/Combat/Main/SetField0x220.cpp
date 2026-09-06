#include <globaldefs.h>

struct S0204a5dc {
    char pad[0x220];
    int field0x220;
};

// USA: func_0204a5dc
ARM void SetField0x220(struct S0204a5dc* p, int v) {
    p->field0x220 = v;
}
