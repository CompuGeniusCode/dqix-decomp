#include <globaldefs.h>

struct Struct020865b0 {
    char pad[0x50];
    int field0x50;
};

// USA: func_020865b0
ARM int GetFieldAt0x50(struct Struct020865b0* p) {
    return p->field0x50;
}
