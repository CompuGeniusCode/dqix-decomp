#include <globaldefs.h>

struct IntField0x68_020377b4 {
    char unk[0x68];
    int field;
};

// USA: func_020377b4
ARM void SetIntAt0x68(struct IntField0x68_020377b4* obj, int value) {
    obj->field = value;
}
