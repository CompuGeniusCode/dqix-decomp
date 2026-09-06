#include <globaldefs.h>

struct IntField0x4_0209a670 {
    char pad[0x4];
    int field;
};

// USA: func_0209a670
ARM int GetIntAt0x4(struct IntField0x4_0209a670* obj) {
    return obj->field;
}
