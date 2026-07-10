#include <globaldefs.h>

struct Sub0209fccc {
    unsigned short value;
};

struct Obj0209fccc {
    unsigned char pad[4];
    char* ctx;
};

// USA: func_0209fccc
ARM int GetScaledGrottoValue0209fccc(struct Obj0209fccc* obj, int mode) {
    struct Sub0209fccc* s = *(struct Sub0209fccc**)(obj->ctx + 0x8e18);
    if (s == NULL) {
        return -1;
    }
    if (mode == 0) {
        return s->value;
    }
    return s->value / 100;
}
