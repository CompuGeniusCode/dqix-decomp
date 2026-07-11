#include <globaldefs.h>

struct IntField0x64_020377c4 {
    char unk[0x64];
    int field;
};

// USA: func_020377c4
ARM void SetIntAt0x64(struct IntField0x64_020377c4* obj, int value) {
    obj->field = value;
}
