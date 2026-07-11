#include <globaldefs.h>

struct IntField0x68_020377bc {
    char unk[0x68];
    int field;
};

// USA: func_020377bc
ARM int GetIntAt0x68(struct IntField0x68_020377bc* obj) {
    return obj->field;
}
