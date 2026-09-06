#include <globaldefs.h>

struct S020a3568 {
    char pad[0x218];
    int field0x218;
};

// USA: func_020a3568
ARM void SetField0x218(struct S020a3568* p, int v) {
    p->field0x218 = v;
}
