#include <globaldefs.h>

typedef int (*Handler_021f736c)(void*);

struct Inner_021f736c {
    char pad[0x18];
    unsigned int field0x18;
};

struct Outer_021f736c {
    char pad[0x10];
    struct Inner_021f736c* field0x10;
};

extern Handler_021f736c data_ov024_021ffda4[];

// USA: func_ov024_021f736c
ARM int DispatchByCategory_021f736c(struct Outer_021f736c* obj) {
    struct Inner_021f736c* inner = obj->field0x10;
    if (!inner) return 0;
    unsigned int idx = (inner->field0x18 << 5) >> 23;
    if (idx >= 0x42) return 0;
    Handler_021f736c fn = data_ov024_021ffda4[idx];
    if (!fn) return 0;
    return fn(obj);
}
