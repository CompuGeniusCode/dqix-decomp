#include <globaldefs.h>

struct PtrField0x1c_020349c0 {
    char unk[0x1c];
    void* field;
};

// USA: func_020349c0
ARM void* GetPointerAt0x1c(struct PtrField0x1c_020349c0* obj) {
    return obj->field;
}
