#include <globaldefs.h>

struct Struct02043110Target {
    char pad[0x8];
    int field8;
};

struct Struct02043110 {
    char pad[0x440];
    struct Struct02043110Target* field440;
};

// USA: func_02043110
ARM void ClearField8ViaPointer0x440(struct Struct02043110* s) {
    struct Struct02043110Target* t = s->field440;
    if (t != 0) {
        t->field8 = 0;
    }
}
