#include <globaldefs.h>

struct Struct022412e8 {
    char pad0[4];
    int field4;
    int field8;
    char pad2[0xc];
    int field0x18;
};

// USA: func_ov031_022412e8
ARM int GetField24_022412e8(Struct022412e8* self, int* out) {
    if (self->field8 == 0 || self->field4 == 0) {
        return -1;
    }
    *out = self->field0x18;
    return self->field4;
}
