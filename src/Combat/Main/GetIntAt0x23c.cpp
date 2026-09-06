#include <globaldefs.h>

struct IntField0x23c_020a27c4 {
    char pad[0x23c];
    int value;
};

// USA: func_020a27c4
ARM int GetIntAt0x23c(struct IntField0x23c_020a27c4* obj) {
    return obj->value;
}
