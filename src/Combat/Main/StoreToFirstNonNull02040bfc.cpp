#include <globaldefs.h>

struct TargetA02040bfc {
    char unk[0x8c];
    int value;
};

struct TargetB02040bfc {
    char unk[0xc8];
    int value;
};

struct TargetC02040bfc {
    char unk[0x2ec];
    int value;
};

struct Obj02040bfc {
    char unk[0x14];
    struct TargetA02040bfc* a;
    struct TargetB02040bfc* b;
    struct TargetC02040bfc* c;
};

// USA: func_02040bfc
ARM void StoreToFirstNonNull02040bfc(struct Obj02040bfc* obj, int value) {
    if (obj->a != 0) {
        obj->a->value = value;
        return;
    }
    if (obj->b != 0) {
        obj->b->value = value;
        return;
    }
    if (obj->c != 0) {
        obj->c->value = value;
    }
}
