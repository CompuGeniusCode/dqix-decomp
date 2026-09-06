#include <globaldefs.h>

extern "C" void __clear(void* dst, int size);

struct Triple02049b54 {
    unsigned int v[3];
};
struct Sub02049b54 {
    unsigned int f0, f4, f8, fc;
};
struct Obj02049b54 {
    unsigned char pad[0x13c];
    struct Sub02049b54* sub;
};

// USA: func_02049b54
ARM struct Triple02049b54 GetSubTriple02049b54(struct Obj02049b54* obj) {
    struct Triple02049b54 local;
    __clear(&local, 0xc);
    if (obj->sub == NULL) return local;
    unsigned int a = obj->sub->f4;
    unsigned int c = obj->sub->fc;
    local.v[0] = a;
    local.v[1] = 0xcc;
    local.v[2] = c;
    return local;
}
