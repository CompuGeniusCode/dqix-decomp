#include <globaldefs.h>

struct StructAA8;
int SetPtrAndShorts(struct StructAA8* obj, int ptr, int value);

struct Source020e03f0 {
    unsigned int lowBits : 12;
    unsigned int highBits : 20;
    int field4;
};

// USA: func_020e03f0
ARM int ApplyPtrAndShorts(struct Source020e03f0* self, struct StructAA8* obj) {
    if (obj == NULL) return 0;
    SetPtrAndShorts(obj, self->field4, self->lowBits);
    return 1;
}
