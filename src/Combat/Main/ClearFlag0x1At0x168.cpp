#include <globaldefs.h>

struct Flags0202ecfc {
    char pad0[0x168];
    unsigned int field168;
};

// USA: func_0202ecfc
ARM void ClearFlag0x1At0x168(struct Flags0202ecfc* p) {
    p->field168 &= ~0x1;
}
