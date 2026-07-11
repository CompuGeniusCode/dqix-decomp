#include <globaldefs.h>

struct PtrField0x1c_020371b0 {
    char unk[0x1c];
    void* field;
};

// USA: func_020371b0
ARM void* GetPointerAt0x1c020371b0(struct PtrField0x1c_020371b0* obj) {
    return obj->field;
}
