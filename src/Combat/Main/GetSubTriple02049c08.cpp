#include <globaldefs.h>

extern "C" void __clear(void* dst, int size);

struct Triple02049c08 {
    unsigned int v[3];
};
struct Sub02049c08 {
    unsigned char pad[0x10];
    unsigned int f10, f14, f18;
};
struct Obj02049c08 {
    unsigned char pad[0x13c];
    struct Sub02049c08* sub;
};

// USA: func_02049c08
ARM struct Triple02049c08 GetSubTriple02049c08(struct Obj02049c08* obj) {
    struct Triple02049c08 local;
    __clear(&local, 0xc);
    if (obj->sub == NULL) return local;
    unsigned int a = obj->sub->f10;
    unsigned int c = obj->sub->f18;
    local.v[0] = a;
    local.v[1] = 0xcc;
    local.v[2] = c;
    return local;
}
