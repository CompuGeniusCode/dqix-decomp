#include <globaldefs.h>

struct IntField0x64_0209fe10 {
    char pad[0x64];
    int field;
};

// USA: func_0209fe10
ARM void SetIntAt0x64_0209fe10(struct IntField0x64_0209fe10* obj, int value) {
    obj->field = value;
}
