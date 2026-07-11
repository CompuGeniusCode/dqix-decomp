#include <globaldefs.h>

struct S02076cc4 {
    char pad[0x16c];
    int field0x16c;
};

// USA: func_02076cc4
ARM void SetField0x16c(struct S02076cc4* p, int v) {
    p->field0x16c = v;
}
