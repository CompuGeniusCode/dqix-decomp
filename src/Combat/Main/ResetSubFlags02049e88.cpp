#include <globaldefs.h>

extern "C" void func_02048cf0(void* obj, int arg);

struct Sub02049e88 {
    unsigned char pad[0x20];
    unsigned int flags;
};
struct Obj02049e88 {
    unsigned char pad[0x13c];
    struct Sub02049e88* sub;
};

// USA: func_02049e88
ARM void ResetSubFlags02049e88(struct Obj02049e88* obj) {
    if (obj->sub == NULL) return;
    obj->sub->flags &= ~0x3;
    obj->sub->flags |= 0x20;
    func_02048cf0(obj, 0);
}
