#include <globaldefs.h>

extern "C" void func_02033ce8(void*);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char fbe;
    unsigned char fbf;
};

// USA: func_02033b68
ARM void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal) {
    if (obj->fbe == newVal) return;
    obj->fbf = obj->fbe;
    obj->fbe = newVal;
    func_02033ce8(obj);
}
