#include <globaldefs.h>

struct Inner374b0 {
    char unk[4];
    int field4;
};

struct Obj374b0 {
    char unk[0x10];
    struct Inner374b0* field10;
};

// USA: func_020374b0
ARM void* GetField4PtrFromField10(struct Obj374b0* obj) {
    struct Inner374b0* p = obj->field10;
    if (p != 0) {
        return &p->field4;
    }
    return 0;
}
