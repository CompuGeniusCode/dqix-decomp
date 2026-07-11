#include <globaldefs.h>

struct Struct020c7b38 {
    char pad[0x70];
    int field0x70;
};

// USA: func_020c7b38
ARM int GetFieldAt0x70(struct Struct020c7b38* p) {
    return p->field0x70;
}
